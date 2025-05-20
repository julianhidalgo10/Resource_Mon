CC = gcc
CFLAGS = -Wall -Wextra -I../src
OBJDIR = ../obj
BINDIR = ../bin

TEST_SRCS = src/cpuinfo_test.c src/meminfo_test.c src/tui_test.c
TEST_EXES = cpuinfo_test meminfo_test tui_test

all: tests

tests: $(TEST_EXES)

cpuinfo_test: src/cpuinfo_test.c
@mkdir -p $(BINDIR)
$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

meminfo_test: src/meminfo_test.c
@mkdir -p $(BINDIR)
$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

tui_test: src/tui_test.c
@mkdir -p $(BINDIR)
$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

.PHONY: clean

clean:
rm -f $(BINDIR)/cpuinfo_test $(BINDIR)/meminfo_test $(BINDIR)/tui_test