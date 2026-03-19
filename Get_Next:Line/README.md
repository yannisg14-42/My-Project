*This project has been created as part of the 42 curriculum by sgarba.*

# 📖<ins>DESCRIPTION

The goal of this 42 project is to implement a function that reads a file
descriptor line by line, returning one line per call including the `\n`
character. It can handle multiple file descriptors and different buffer sizes.

# 🔎<ins>HOW DOES IT WORK ?

`get_next_line` uses a **static buffer** that persists between function calls.
Each call reads `BUFFER_SIZE` bytes into a temporary buffer, appends it to the
static buffer, then checks if a `\n` was found. If yes, it extracts and returns
that line and shifts the static buffer to keep only what comes after the `\n`.
If no `\n` is found and the file is exhausted, it returns the remaining content.

## 🔨<ins>Algorithm and Data Structure

A static `char *` was chosen to persist state between calls without requiring
the caller to manage any external state. The buffer grows dynamically via
`malloc` — we never know how long a line will be in advance. Helper functions
cleanly separate each responsibility: reading, extracting, shifting, and appending.

# ⚙️<ins>INSTRUCTION

Compile with a custom buffer size:
`cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c yourfile.c`

# 📎<ins>RESOURCES

[Man page of read()](https://man7.org/linux/man-pages/man2/read.2.html)

[Static variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/)

I used AI for in depth conceptual explanation and Socratic learning,
not direct code generation.
