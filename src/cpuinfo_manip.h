#ifndef CPUINFO_MANIP_H
#define CPUINFO_MANIP_H

#define CPU_NAME_MAX_LEN 128
#define CPU_VENDOR_MAX_LEN 64

typedef struct {
    char name[CPU_NAME_MAX_LEN];
    char vendor[CPU_VENDOR_MAX_LEN];
    int cores;
    int threads;
    float *usage_percent;  // Array con porcentaje de uso por hilo
    int usage_len;
} CPUInfo;

int cpuinfo_init(CPUInfo *cpu);
int cpuinfo_update_usage(CPUInfo *cpu);
void cpuinfo_free(CPUInfo *cpu);

#endif // CPUINFO_MANIP_H