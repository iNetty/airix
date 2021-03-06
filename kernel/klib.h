#ifndef KLIB_H
#define KLIB_H

#include <kernel/base.h>

struct trap_frame;

/* Set GDTR/IDTR */
void set_gdtr(const void *gdtr);
void set_idtr(const void *idtr);

/* Setup paging directory */
void set_cr3(physical_addr_t page_directory);

/* Set TSS selector */
void set_tss(uint16_t selector);

/* IO functions */
uint8_t in_byte(uint16_t port);
uint32_t in_dword(uint16_t port);
void insw(uint16_t port, uint32_t count, void *buffer);
void out_byte(uint16_t port, uint8_t value);
void out_dword(uint16_t port, uint32_t value);

/* Close/start interrupt */
void close_int();
void start_int();

void halt();

/* Switch kernel stack context */
struct kstack_context;
void switch_kcontext(struct kstack_context **cur,
                     struct kstack_context *new);

/* Returns to user space */
void ret_user_space(struct trap_frame *frame);

/* System call entry */
void syscall_entry();

/* IRQ ISR entry */
void isr_entry0();
void isr_entry1();
void isr_entry2();
void isr_entry3();
void isr_entry4();
void isr_entry5();
void isr_entry6();
void isr_entry7();
void isr_entry8();
void isr_entry9();
void isr_entry10();
void isr_entry11();
void isr_entry12();
void isr_entry13();
void isr_entry14();
void isr_entry15();

/* Exceptions entry */
void divide_by_zero_entry();
void debug_entry();
void non_maskable_int_entry();
void breakpoint_entry();
void overflow_entry();
void bound_range_exceeded_entry();
void invalid_opcode_entry();
void device_not_available_entry();
void double_fault_entry();
void invalid_tss_entry();
void segment_not_present_entry();
void stack_segment_fault_entry();
void general_protection_fault_entry();
void page_fault_entry();
void fp_exception_entry();
void alignment_check_entry();
void machine_check_entry();
void simd_fp_exception_entry();
void virtualization_entry();
void security_exception_entry();

/* Helper functions */
void put_char_at(uint32_t line, uint32_t column, char c);
void clear_screen();
void printk(const char *fmt, ...);
void panic(const char *fmt, ...);

#endif /* KLIB_H */
