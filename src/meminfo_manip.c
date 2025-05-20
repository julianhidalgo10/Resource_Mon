#include "meminfo_manip.h"
#include <stdio.h>
#include <stdlib.h>

// Funciones para leer /proc/meminfo

int meminfo_init(MemInfo *mem) {
    // Inicializa estructura mem (por ejemplo, leer totales)
    mem->total_mem_mb = 0;
    mem->swap_mem_mb = 0;
    mem->used_mem_percent = 0.0f;
    mem->used_swap_percent = 0.0f;
    return 0;
}

int meminfo_update(MemInfo *mem) {
    // Aquí lee /proc/meminfo y actualiza uso de memoria y swap
    // Por ahora, valores dummy
    mem->total_mem_mb = 8000;  // Ejemplo 8GB
    mem->swap_mem_mb = 2000;   // Ejemplo 2GB
    mem->used_mem_percent = (float)(rand() % 100);
    mem->used_swap_percent = (float)(rand() % 100);
    return 0;
}