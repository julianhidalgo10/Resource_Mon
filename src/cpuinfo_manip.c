#include "cpuinfo_manip.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aquí debes implementar la lectura de /proc/cpuinfo y /proc/stat para llenar CPUInfo

int cpuinfo_init(CPUInfo *cpu) {
    // Inicializa el struct CPUInfo leyendo /proc/cpuinfo para llenar nombre, vendor, cores, threads
    // Reservar memoria para usage_percent según número de hilos
    // Por simplicidad, aquí inicializamos con valores dummy
    strcpy(cpu->name, "Generic CPU");
    strcpy(cpu->vendor, "Generic Vendor");
    cpu->cores = 4;
    cpu->threads = 8;
    cpu->usage_len = cpu->threads;
    cpu->usage_percent = (float *)malloc(sizeof(float) * cpu->usage_len);
    for (int i = 0; i < cpu->usage_len; i++) {
        cpu->usage_percent[i] = 0.0f;
    }
    return 0;
}

int cpuinfo_update_usage(CPUInfo *cpu) {
    // Aquí se debe actualizar el porcentaje de uso por hilo leyendo /proc/stat
    // Por ahora llenamos con valores dummy para prueba
    for (int i = 0; i < cpu->usage_len; i++) {
        cpu->usage_percent[i] = (float)(rand() % 100);
    }
    return 0;
}

void cpuinfo_free(CPUInfo *cpu) {
    free(cpu->usage_percent);
    cpu->usage_percent = NULL;
}