PYTHON	= $(VENV)/bin/python3
PIP		= pip
SRC		= a_maze_ing.py
CONFIG	= config.txt
VENV	= matrix

$(VENV):
	python3 -m venv $(VENV)

install: $(VENV)
	$(PIP) install -r requirements.txt
	$(PIP) install -e .

all: run

run:
	python3 a_maze_ing.py config.txt $(ARGS)

test: 
	@echo "Running test..."
	$(PYTHON) -m pytest mytest.py

debug:
	$(PYTHON) -m pdb $(SRC)

lint:
	flake8 src/ a_maze_ing.py maze_functions/
	mypy src/ a_maze_ing.py maze_functions/ --explicit-package-bases

lint-strict:
	flake8 src/ a_maze_ing.py maze_functions/
	mypy --strict src/ a_maze_ing.py maze_functions/ --explicit-package-bases

clean:
	rm -rf .mypy_cache .pytest_cache

.PHONY: all run test debug lint lint-strict clean