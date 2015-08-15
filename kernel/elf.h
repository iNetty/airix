#ifndef ELF_H
#define ELF_H

#include <kernel/base.h>
#include <kernel/process.h>

/*
 * Expand elf content into process address space, and set
 * the entry of the process, returns true when success.
 */
bool elf_load_program(const char *elf_data, size_t size,
                      struct process *proc);

#endif /* ELF_H */
