#include "tui.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

static struct termios orig_termios;

void tui_init(void) {
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);  // Deshabilitar buffer y eco
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // No bloqueante
}

void tui_destroy(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void tui_draw(const CPUInfo *cpu, const MemInfo *mem) {
    printf("\033[H\033[J"); // Limpia pantalla
    printf("CPU: %s (%s)\n", cpu->name, cpu->vendor);
    printf("Cores: %d, Threads: %d\n", cpu->cores, cpu->threads);
    printf("Uso CPU por hilo:\n");
    for (int i = 0; i < cpu->usage_len; i++) {
        printf("  Hilo %d: %.2f%%\n", i, cpu->usage_percent[i]);
    }
    printf("\nMemoria física instalada: %ld MB\n", mem->total_mem_mb);
    printf("Memoria swap: %ld MB\n", mem->swap_mem_mb);
    printf("Uso memoria física: %.2f%%\n", mem->used_mem_percent);
    printf("Uso swap: %.2f%%\n", mem->used_swap_percent);
    printf("\nPresione 'q' para salir.\n");
}

int tui_poll_key(void) {
    char c;
    if (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == 'q') return 1;
    }
    return 0;
}