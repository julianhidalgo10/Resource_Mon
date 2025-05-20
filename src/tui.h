#ifndef TUI_H
#define TUI_H

#include "cpuinfo_manip.h"
#include "meminfo_manip.h"

void tui_init(void);
void tui_destroy(void);
void tui_draw(const CPUInfo *cpu, const MemInfo *mem);
int tui_poll_key(void);

#endif // TUI_H