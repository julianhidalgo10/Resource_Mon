#include "cpuinfo_manip.h"
#include "meminfo_manip.h"
#include "tui.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static volatile int running = 1;

void handle_sigint(int sig) {
    (void)sig;
    running = 0;
}

int main(void) {
    CPUInfo cpu;
    MemInfo mem;

    signal(SIGINT, handle_sigint);

    cpuinfo_init(&cpu);
    meminfo_init(&mem);
    tui_init();

    while (running) {
        cpuinfo_update_usage(&cpu);
        meminfo_update(&mem);
        tui_draw(&cpu, &mem);

        if (tui_poll_key()) break;

        sleep(1);
    }

    tui_destroy();
    cpuinfo_free(&cpu);
    printf("Programa terminado.\n");
    return 0;
}