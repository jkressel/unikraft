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

#define __flexos_morello_gate1(key_from, key_to, fname, arg1) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"str c9, [sp, #-16]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c16, c17, [sp, #-32]!\n"		\
	:								\
	:								\
	: "sp"							\
);									\
	\
	\
	\
/* x12 will hold tsb sp and x13 will hold tsb fp */ 	\
__asm__ (	\
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
__asm__ (	\
	"mov x10, sp\n"	\
	"stp x10, fp, [x11]\n"	\
	:		\
	: 	\
	: "x10", "memory"	\
);	\
	\
	\
/* Now we need to load the dest compartment id into a register */	\
__asm__ (	\
	"mov x10, %0\n"	\
	:				\
	: "r"(key_to)	\
	: "x10"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
__asm__ (	\
	"mov c0, %0\n"	\
	:				\
	: "r"(arg1)	\
	: "c0"	\
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
	: "c11", "c29", "c30"	\
);	\
/* Need to do reentry */	\
/* - Restore stack and frame and tsb*/	\
/* - Pop registers saved */	\
/* restore tsb */ 	\
__asm__ (	\
	"mov x10, %0\n"\
	"mul x11, x10, %1\n"	\
	"add x11, x11, %2\n"	\
	"ldp x12, x13, [sp], #16\n"	\
	"stp x12, x13, [x11]\n"\
	:				\
	: "r"(uk_thread_get_tid()), "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c16, c17, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldr c9, [sp], #16\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9"							\
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