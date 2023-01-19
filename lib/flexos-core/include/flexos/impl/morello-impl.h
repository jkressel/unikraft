#ifndef FLEXOS_MORELLO_IMPL_H
#define FLEXOS_MORELLO_IMPL_H

#include <flexos/impl/morello.h>
#include <uk/page.h>
#include <uk/arch/lcpu.h>

/*
* What does the switcher need?
* Needs the sp to switch to
* Needs the fp to switch to
* Needs the source compartment id
* Needs the dest compartment id
* Function arguments
*/

static inline
int uk_thread_get_tid(void)
{
	unsigned long sp = ukarch_read_sp();
	return *((int *) round_pgup((unsigned long) ((sp & STACK_MASK_TOP) + 1)));
}

#define __flexos_morello_gate1(key_from, key_to, f_ptr, arg1) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c18, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c16, c17, [sp, #-32]!\n"		\
	"stp c29, c31, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	:								\
	:								\
	: "sp"							\
);									\
	\
	\
	\
/* x12 will hold tsb sp and x13 will hold tsb fp */ 	\
__asm__ volatile(	\
	"mov x10, %0\n"	\
	"mul x11, x10, %1\n"	\
	"add x11, x11, %2\n"	\
	"ldp x12, x13, [x11]\n"	\
	"stp x12, x13, [sp, #-16]!\n"	\
	:				\
	: "r"(uk_thread_get_tid()), "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp"	\
);	\
	\
	\
	\
/* backup the current sp and fp */ 	\
/*tsb_comp ## key_from[tid].sp = register asm("sp");*/	\
/*tsb_comp ## key_from[tid].bp = register asm("fp");*/	\
/* x11 hold the base of tsb_comp ## key_from as calculated above */ 	\
\
__asm__ volatile(	\
	"mov x10, sp\n"	\
/*This is to allow us to store things like ddc, return address */	\
	"sub x10, x10, #32\n"	\ 
	"stp x10, fp, [x11]\n"	\
	:		\
	: 	\
	: "x10", "memory"	\
);	\
	\
	\
/* Now we need to load the dest compartment id into a register and the number of arguments*/	\
/* TODO: tying to load the address of tsb comp for the target may not work, may need to revist this in the future*/	\
__asm__ volatile(	\
	"mov x8, %0\n"	\
	"mov x7, %1\n"	\
	"mov x9, %2\n"	\
	"mov x13, %3\n"	\
	"mov x14, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x8", "x7", "x9", "x13", "x14"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
__asm__ volatile(	\
	"mov x0, %0\n"	\
	:				\
	: "r"(arg1)	\
	: "c0", "x7", "x8", "x9", "x13", "x14"	\
); 	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c11, [%0]\n"	\
	"ldpblr c29, [c11]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "c11", "c29", "c30", "x9", "x10", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
);	\
\
\
\
__asm__ volatile (	\
	"mov x10, %0\n"\
	"msr ddc, c29\n"	\
	:	\
	:	"r"(uk_thread_get_tid())	\
	: "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x10"	\
);	\
/* Need to do reentry */	\
/* - Restore stack and frame and tsb*/	\
/* - Pop registers saved */	\
/* restore tsb */ 	\
__asm__ volatile(	\
	"mul x11, x10, %0\n"	\
	"add x11, x11, %1\n"	\
	"ldp x12, fp, [x11]\n"	\
	"mov sp, x12\n"	\
	"ldp x12, x13, [sp, #32]!\n"	\
	"add sp, sp, #16\n"	\
	"stp x12, x13, [x11]\n"\
	:				\
	: "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp", "fp"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c29, c31, [sp], #32\n"		\
	"ldp c16, c17, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c18, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c18"							\
);	\
} while (0)

#define __flexos_morello_gate1_r(key_from, key_to, retval, fname, arg1)\
do {									\
	\
} while (0)

#define _flexos_morello_gate(N, key_from, key_to, fname, ...)		\
do {									\
	UK_CTASSERT(N <= 6);						\
	__flexos_morello_gate ## N (key_from, key_to, fname __VA_OPT__(,) __VA_ARGS__); \
} while (0)

#define _flexos_morello_gate_r(N, key_from, key_to, retval, fname, ...)\
do {									\
	UK_CTASSERT(N <= 6);						\
	__flexos_morello_gate ## N ## _r (key_from, key_to, retval, fname __VA_OPT__(,) __VA_ARGS__); \
} while (0)

#endif