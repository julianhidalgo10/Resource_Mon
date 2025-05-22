# Resource Monitor – `test/` Directory

This directory contains unit tests for the `resource_mon` project. The tests verify the correct functionality of each module.

## Directory Structure

- `cpuinfo_test.c`: Tests CPU data reading and parsing from `/proc/cpuinfo`.
- `meminfo_test.c`: Tests memory data reading and parsing from `/proc/meminfo`.
- `tui_test.c`: Tests display output functions.
- `src/Makefile`: Compiles all test files into executables.

## Requirements

- Linux system with `/proc`
- GCC compiler

## How to Compile Tests

From inside the `test/src/` directory, run:

```bash
make
```

This will generate the following executables:

- `cpuinfo_test`
- `meminfo_test`
- `tui_test`

## How to Run Tests

Run each test individually from the `test/src/` folder:

```bash
./cpuinfo_test
./meminfo_test
./tui_test
```

## Sample Output

```text
Running CPU info test...
Model: Intel(R) Core(TM) i7-8650U CPU @ 1.90GHz
Cores: 4
[PASS]

Running memory info test...
Total memory: 16319884 kB
Free memory : 10345600 kB
[PASS]

Running TUI test...
TUI display output simulated.
[PASS]
```

## Notes

- These tests rely on live data from the system, so exact values may differ.
- They do not use any external libraries.
- All test programs are simple C executables for quick validation.
