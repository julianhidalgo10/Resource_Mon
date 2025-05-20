CC = gcc
CFLAGS = -Wall -Wextra -I.
OBJDIR = ../obj
BINDIR = ../bin

SRCS = cpuinfo_manip.c meminfo_manip.c tui.c resource_mon.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c
@mkdir -p $(OBJDIR)
$(CC) $(CFLAGS) -c $< -o $@

resource_mon: $(OBJS)
@mkdir -p $(BINDIR)
$(CC) $(CFLAGS) $^ -o $(BINDIR)/$@

.PHONY: clean

clean:
rm -f $(OBJDIR)/*.o
rm -f $(BINDIR)/resource_mon