# Resource Monitor – `src/` Directory

This directory contains the source code for `resource_mon`, a simple terminal-based resource monitor for Linux systems written in C.

## Directory Structure

- `resource_mon.c`: Main program that integrates all modules.
- `cpuinfo_manip.c/.h`: Functions for reading and parsing CPU information from `/proc/cpuinfo`.
- `meminfo_manip.c/.h`: Functions for reading and parsing memory information from `/proc/meminfo`.
- `tui.c/.h`: Functions for displaying data in a simple text user interface (TUI).
- `Makefile`: Build script to compile the monitor.

## Requirements

- Linux or UNIX-like operating system
- GCC compiler
- Access to `/proc/cpuinfo` and `/proc/meminfo`

## How to Compile

Open a terminal in the root folder of the project and run:

```bash
make
```

The executable will be created in the `bin/` folder as `resource_mon`.

## How to Run

After compiling, run the monitor with:

```bash
./bin/resource_mon
```

## Sample Output

```text
==================== RESOURCE MONITOR ====================
CPU:
  Model: Intel(R) Core(TM) i7-8650U CPU @ 1.90GHz
  Cores: 4
  Threads: 8

MEMORY:
  Total: 16319884 kB
  Free : 10345600 kB
  Used : 5974284 kB

Refreshing every 1 second...
==========================================================
```

## Notes

- The program refreshes data every second.
- It does not require root privileges.
- Works only on systems with `/proc` filesystem (Linux-based).
