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

#define __flexos_morello_gate1(key_from, key_to, fname, arg1)		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
	\
__asm__ (	\
	"stp c9, c10, [sp, #-32]!\n"	\
	"stp c11, c12, [sp, #-32]!\n"	\
	"stp c13, c14, [sp, #-32]!\n"	\
	"stp c15, c16, [sp, #-32]!\n"	\
	"str c17, [sp, #-16]!\n"		\
	:								\
	:								\
	: "sp"							\
);									\
	\
	\
/* - need to pass thread id? No, need to pass the sp and fp. Also need to backup current. 	*/	\
\
/* x12 will hold tsb sp and x13 will hold tsb fp */ 	\
__asm__ (	\
	"mov x10, %0\n"	\
	"mul x11, x10, %1\n"	\
	"add x11, x11, %2\n"	\
	"ldr x12, [x11]\n"	\
	"ldr x13, [x11, #8]\n"	\
	"stp x12, x13, [sp, #-32]!\n"	\
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
\
/* - need to handle arguments passed	\
* - need to load switcher caps			\
* - need to pass the source and dest compartment	\
* - invoke the switcher	*/ \
	\
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