#ifndef MEMINFO_MANIP_H
#define MEMINFO_MANIP_H

typedef struct {
    long total_mem_mb;
    long swap_mem_mb;
    float used_mem_percent;
    float used_swap_percent;
} MemInfo;

int meminfo_init(MemInfo *mem);
int meminfo_update(MemInfo *mem);

#endif // MEMINFO_MANIP_H