*This project has been created as part of the 42 curriculum by sgarba, edraheim.*

# A-MAZE-ING-42

# Description

A-MAZE-ING is a maze generator and solver written in Python, developed as
part of the 42 curriculum. The project has two parts:

1. **`mazegen`** — a standalone, reusable, pip-installable Python package
   that generates mazes, solves them, and exposes the underlying maze
   structure for use in other projects.
2. **`a_maze_ing.py`** — a command-line program that reads maze
   configuration from a `config.txt` file, generates a maze using the
   `mazegen` package, displays it in the terminal with colors, and offers
   an interactive menu to explore, solve, and save it.

The goal of the project was not just to generate a maze, but to build the
generator as an independent, reusable module — decoupled from any
particular display or interaction logic — so it can be picked up and used
in future, unrelated projects.

# Repository structure

```
amazing/
├── pyproject.toml          # Package metadata, used to build mazegen
├── LICENSE.md               # MIT license
├── README.md                # This file
├── Makefile                 # Commands to install, build, run, and test
├── config.txt                # Example maze configuration
├── a_maze_ing.py             # Entry point of the interactive program
├── maze_functions/           # Program-specific logic (not part of the package)
│   ├── file_reader.py         # Config file parsing
│   ├── data_validator.py      # Config validation and custom exceptions
│   ├── show_maze.py           # Terminal rendering
│   ├── color.py               # Terminal color helpers
│   └── menu.py                # Interactive menu
├── src/
   └── mazegen/               # The reusable package (see below)
       ├── __init__.py
       └── mazegen.py

```

# Instructions
## How to run the program
To run the program in a clean enviroment 
creat a new virtual enviroment and activate it.
```bash
python3 -m venv clean_venv
source clean_venv/bin/activate
```
After you have entered the venv install all packages.
```bash
make install
```
Then you can start the program with the command
```bash
make run
```
The menu will guide you through the program.Enjoy!


## Installing the maze generator package

`mazegen` is built as a standard Python package using `setuptools`, and can
be built and installed independently of the rest of this repository.

From the root of this repository:

```bash
pip install build --break-system-packages
python3 -m build
```

This creates a `dist/` directory containing:

- `dist/mazegen-1.1-py3-none-any.whl`
- `dist/mazegen-1.1.tar.gz`
We moove one of the file at the repo root afterward.

Install it into any project (a virtual environment is recommended):

```bash
pip install dist/mazegen-1.1-py3-none-any.whl
```

Then import it:

```python
from mazegen import MazeGenerator
```

### Basic usage

```python
from mazegen import MazeGenerator

# width, height, entry, exit, seed, perfect
maze = MazeGenerator(20, 15, (1, 1), (18, 13), 42, False)
maze.generate()
```

## Custom parameters

- `width`, `height` — dimensions of the maze, in cells.
- `entry`, `exit` — `(x, y)` coordinates of the start and end cells.
- `seed` — an integer seed for the random number generator. The same seed
  always produces the same maze, which is useful for testing and
  reproducibility.
- `perfect` — when `True`, the maze has exactly one path between any two
  cells (no loops). When `False`, extra dead-ends's walls are opened, creating
  loops for a pac-man board (see below).

## Accessing the generated structure

```python
grid = maze.grid  # list[list[int]]
```

Each cell is an integer bitmask describing which of its four walls are
closed:

| Bit | Value | Wall  |
|-----|-------|-------|
| 0   | 1     | North |
| 1   | 2     | East  |
| 2   | 4     | South |
| 3   | 8     | West  |

A value of `15` means all four walls are closed; `0` means the cell is
open on every side.

## Accessing a solution

```python
solution = maze.solution  # list[tuple[int, int]], the shortest path from entry to exit
```

The path is also available as a standalone function, usable independently
of the `MazeGenerator` class:

```python
from mazegen import shortest_path

path = shortest_path(grid, (1, 1), (18, 13))
```

## Running the interactive program

To run the full program (not just the package):

```bash
make run
```

To run it with the "perfect" flag:

```bash
make run ARGS="--perfect"
```

The program expects a config file path as an argument, e.g.:

```bash
python3 a_maze_ing.py config.txt
```

Once running, an interactive menu lets you change the display color,
generate a new maze, toggle the solution path, save the maze to a file, or
quit.


# Config file structure

The `config.txt` file stores the maze configuration as `KEY=VALUE` pairs,
one per line, with all values as strings:

```
WIDTH=20
HEIGHT=15
ENTRY=0,5
EXIT=10,6
OUTPUT_FILE=maze.txt
PERFECT=False
SEED=20
```

| Key           | Meaning                                                |
|---------------|---------------------------------------------------------|
| `WIDTH`       | Number of cells horizontally (minimum 12)                |
| `HEIGHT`      | Number of cells vertically (minimum 9)                   |
| `ENTRY`       | `x,y` coordinates of the entry cell                       |
| `EXIT`        | `x,y` coordinates of the exit cell                        |
| `OUTPUT_FILE` | Path the maze is written to when saved from the menu      |
| `PERFECT`     | `True` for a loop-free maze, `False` to add loops          |
| `SEED`        | Integer seed for reproducible maze generation              |

Invalid configuration (out-of-range size, entry/exit outside the grid,
entry equal to exit, or an invalid `PERFECT` value) raises a dedicated
exception (`SizeError`, `OutOfBoundsError`, `LessThanZeroError`, or
`PerfectError`) with a descriptive message.

## Saved maze format

When a maze is saved via the menu, the output file stores each row of the
grid as one hexadecimal digit per cell (each cell value fits in 4 bits),
followed by a blank line, the entry and exit coordinates, and the solution
path encoded as a string of direction letters (`N`, `E`, `S`, `W`):

```
d5555395555539395793
b9513aa97953c6a8556a
...
1,2
12,12
NEESSSWWNWSSSSESEEEESSWWSSESWSEEENENWWNEEEEENESENESSW
```

# Maze generation algorithm — DFS

## 42 pattern 
first of all the 42 pattern is marked before the carving, so that DFS knows which cells belong to the pattern, and should not be opened.

The maze is generated using **DFS (depth-first search)**, implemented
iteratively with an explicit stack rather than recursion (to avoid
Python's recursion depth limit on larger mazes).

Starting from a cell, the algorithm repeatedly moves into a random
unvisited neighboring cell, opening the wall between the two. When it
reaches a cell with no unvisited neighbors (a dead end), it backtracks —
using the stack — to the last cell that still has an unvisited neighbor,
and continues from there. This repeats until every cell has been visited.

**Why DFS:** DFS naturally produces a "perfect maze" — a maze in which
there is exactly one path between any two cells, with no loops and no
inaccessible areas. This matches the `PERFECT=True` requirement directly.
For `PERFECT=False`, we additionally run a loop-adding pass (`add_loops`)
after the DFS carve, which opens a limited number of extra walls (without
ever opening a wall belonging to a cell reserved for the "42" pattern,
and without creating large open 3x3 areas) to introduce alternate routes.

## Path-finding algorithm — BFS

The shortest path between the entry and exit is found using **BFS
(breadth-first search)**. Starting from the entry cell, BFS explores the
maze one step at a time in every open direction, expanding outward evenly
in "waves." Each newly discovered cell records which cell it was reached
from. As soon as the exit cell is reached, the path is reconstructed by
walking this record backward from the exit to the entry, then reversing
it.

**Why BFS:** because every move between adjacent cells costs the same (one
step), BFS is guaranteed to find the shortest path — the first time it
reaches the exit, it has done so via the fewest possible steps. This
would not be guaranteed by DFS, which can take arbitrarily long detours
before finding the exit.

## Reusability

The `mazegen` package is entirely self-contained: it has no dependency on
`a_maze_ing.py` or on any of the display/menu logic in `maze_functions/`.
It can be built, installed via `pip`, and imported into any other Python
project independently of this repository. The public interface exposed
through `mazegen/__init__.py` is the `MazeGenerator` class, covering
generation (`generate()`), structure access (`.grid`), and solution access
(`.solution` / `shortest_path()`).

Everything under `maze_functions/` (config parsing, terminal rendering,
color handling, the interactive menu) is specific to this program and is
not part of the reusable package.

# Team and project management

## Roles

- **sgarba** designed and implemented the maze generation core: the DFS
  carving algorithm, the connectivity pre-check, the 3x3 guard, the entry/exitvalidation, wall bitmask handling, the "42" pattern and loop
  addition, and the `MazeGenerator` class itself.
- **edraheim** implemented the BFS solver, the terminal rendering and
  color system, the interactive menu, configuration parsing and
  validation, and packaged the project (`pyproject.toml`, `Makefile`,
  `README.md`, `LICENSE.md`).

## Planning

<!-- Replace with your actual timeline. -->
We split the project along the generator/consumer boundary from the
start: one of us focused on the maze generation package itself, the other
on the program that consumes it (config parsing, display, interaction).
This let both parts progress in parallel once the shape of the shared
`MazeGenerator` interface was agreed on early.

## What worked well / what could be improved

<!-- Replace with your actual retrospective. -->
Agreeing on the `MazeGenerator`'s public interface (constructor
parameters, `.grid`, `.solution`) early on made it possible to work in
parallel without blocking each other. Packaging the module correctly
(directory layout, `pyproject.toml`, distinguishing the package's import
name from its distribution name) took more iteration than expected, and
would be worth setting up first next time, before writing much of the
generation logic.

## Tools used

<!-- Replace with what you actually used. -->
- `mypy --strict` and `flake8` for static type checking and linting
- `pytest` for automated testing of the maze generation and solving logic
- `git` for version control and collaboration

# Resources

- [Maze generation DFS algorithm — Medium](https://medium.com/@nacerkroudir/randomized-depth-first-search-algorithm-for-maze-generation-fb2d83702742)
- [Breadth-first search- Mazesolver — RealPython](https://realpython.com/python-maze-solver/)
- [Python Packaging User Guide](https://packaging.python.org/)
- [pytest documentation](https://docs.pytest.org/)
- [Makefiles in Python](https://medium.com/@petrica.leuca/what-does-a-makefile-do-5e987d537235)
- [Python Packaging User Guide](https://packaging.python.org/)
- [Pytest documentation](https://docs.pytest.org/)
- [Bitwise operations](https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/)
- [Difference between lists, sets and tuples](https://www.geeksforgeeks.org/python/difference-between-list-vs-set-vs-tuple-in-python/)

# AI usage

AI assistance (Claude) was used during this project for:

- Debugging Python tracebacks and mypy/pytest errors (e.g. circular
  imports, package build and import path issues, type annotation errors
  under `mypy --strict`).
- Explaining core concepts (DFS vs. BFS, Python module/package/import
  mechanics, Makefile syntax, ANSI terminal color codes) rather than
  writing the algorithms directly.
- Reviewing and correcting small code snippets for bugs (e.g. operator
  precedence mistakes, off-by-one errors, incorrect argument ordering).
- Drafting and correcting this `README.md` file.

The core maze generation (DFS), solving (BFS), and package structure were
designed and implemented by the team; AI was used as a debugging aid and
documentation tool rather than to generate the project's core logic.
