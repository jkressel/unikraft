#ifndef FLEXOS_MORELLO_IMPL_H
#define FLEXOS_MORELLO_IMPL_H

#include <flexos/impl/morello.h>
#include <uk/page.h>
#include <uk/arch/lcpu.h>


static inline
int uk_thread_get_tid(void)
{
	unsigned long sp = ukarch_read_sp();
	return *((int *) round_pgup((unsigned long) ((sp & STACK_MASK_TOP) + 1)));
}

#define IS_CAP(arg)	(sizeof(arg) == 16)

#define __flexos_morello_move_argument1_cap(arg) 	\
do {	\
	__asm__ (	\
	"mov c0, %0\n"	\
	:				\
	: "r"(arg)	\
	: "c0", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument2_cap(arg) 	\
do {	\
	__asm__ (	\
	"mov c1, %0\n"	\
	:				\
	: "r"(arg)	\
	: "c1", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument3_cap(arg) 	\
do {	\
	__asm__ (	\
	"mov c2, %0\n"	\
	:				\
	: "r"(arg)	\
	: "c2", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument4_cap(arg) 	\
do {	\
	__asm__ (	\
	"mov c3, %0\n"	\
	:				\
	: "r"(arg)	\
	: "c3", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument5_cap(arg) 	\
do {	\
	__asm__ (	\
	"mov c4, %0\n"	\
	:				\
	: "r"(arg)	\
	: "c4", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument6_cap(arg) 	\
do {	\
	__asm__ (	\
	"mov c5, %0\n"	\
	:				\
	: "r"(arg)	\
	: "c5", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument7_cap(arg) 	\
do {	\
	__asm__ (	\
	"mov c6, %0\n"	\
	:				\
	: "r"(arg)	\
	: "c6", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument1_int(arg) 	\
do {	\
	__asm__ (	\
	"mov x0, %0\n"	\
	:				\
	: "r"(arg)	\
	: "x0", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument2_int(arg) 	\
do {	\
	__asm__ (	\
	"mov x1, %0\n"	\
	:				\
	: "r"(arg)	\
	: "x1", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument3_int(arg) 	\
do {	\
	__asm__ (	\
	"mov x2, %0\n"	\
	:				\
	: "r"(arg)	\
	: "x2", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
); 	\
} while (0)

#define __flexos_morello_move_argument4_int(arg) 	\
do {	\
	__asm__ (	\
	"mov x3, %0\n"	\
	:				\
	: "r"(arg)	\
	: "x3", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
); 	\
} while (0)

#define __flexos_morello_move_argument5_int(arg) 	\
do {	\
	__asm__ (	\
	"mov x4, %0\n"	\
	:				\
	: "r"(arg)	\
	: "x4", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument6_int(arg) 	\
do {	\
	__asm__ (	\
	"mov x5, %0\n"	\
	:				\
	: "r"(arg)	\
	: "x5", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define __flexos_morello_move_argument7_int(arg) 	\
do {	\
	__asm__ (	\
	"mov x6, %0\n"	\
	:				\
	: "r"(arg)	\
	: "x6", "x8", "x9", "x10", "x11", "x12", "x13", "x14"	\
);	\
} while (0)

#define flexos_morello_move_arg_int_into_reg(arg, number)	\
	switch (number)	\
	{	\
	case 1:	\
		__flexos_morello_move_argument1_int(arg);	\
		break;	\
	case 2:	\
		__flexos_morello_move_argument2_int(arg);	\
		break;	\
	case 3:	\
		__flexos_morello_move_argument3_int(arg);	\
		break;	\
	case 4:	\
		__flexos_morello_move_argument4_int(arg);	\
		break;	\
	case 5:	\
		__flexos_morello_move_argument5_int(arg);	\
		break;	\
	case 6:	\
		__flexos_morello_move_argument6_int(arg);	\
		break;	\
	case 7:	\
		__flexos_morello_move_argument7_int(arg);	\
		break;	\
	default:	\
		break;	\
	}	

#define flexos_morello_move_arg_cap_into_reg(arg, number)	\
	switch (number)	\
	{	\
	case 1:	\
		__flexos_morello_move_argument1_cap(arg);	\
		break;	\
	case 2:	\
		__flexos_morello_move_argument2_cap(arg);	\
		break;	\
	case 3:	\
		__flexos_morello_move_argument3_cap(arg);	\
		break;	\
	case 4:	\
		__flexos_morello_move_argument4_cap(arg);	\
		break;	\
	case 5:	\
		__flexos_morello_move_argument5_cap(arg);	\
		break;	\
	case 6:	\
		__flexos_morello_move_argument6_cap(arg);	\
		break;	\
	case 7:	\
		__flexos_morello_move_argument7_cap(arg);	\
		break;	\
	default:	\
		break;	\
	}	


#define __flexos_morello_gate0(key_from, key_to, f_ptr) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30"							\
);	\
} while (0)

#define __flexos_morello_gate0_r(key_from, key_to, retval_ptr, f_ptr)\
do {									\
	/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
\
\
\
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
	"add sp, sp, #256\n"	\
	:				\
	: "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile (	\
	"mov x11, %0\n"\
	"str x0, [x11]\n"	\
	"sub sp, sp, #256\n"	\
	:	\
	:	"r"(&retval_ptr)	\
	: "x0", "x11", "x10"	\
);	\
\
\
\
__asm__ volatile(	\
	"ldp c29, c30, [sp, #-32]!\n"		\
	"ldp c27, c28, [sp, #-32]!\n"		\
	"ldp c25, c26, [sp, #-32]!\n"		\
	"ldp c23, c24, [sp, #-32]!\n"		\
	"ldp c21, c22, [sp, #-32]!\n"		\
	"ldp c19, c20, [sp, #-32]!\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30", "sp"							\
);	\
} while (0)


#define __flexos_morello_gate1(key_from, key_to, f_ptr, arg1) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30"							\
);	\
} while (0)

#define __flexos_morello_gate1_r(key_from, key_to, retval_ptr, f_ptr, arg1)\
do {									\
	/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
/* x12 will hold tsb sp and x13 will hold tsb fp */ 	\
	"mov x10, %0\n"	\
	"mul x11, x10, %1\n"	\
	"add x11, x11, %2\n"	\
	"ldp x12, x13, [x11]\n"	\
	"stp x12, x13, [sp, #-16]!\n"	\
	/* backup the current sp and fp */ 	\
/*tsb_comp ## key_from[tid].sp = register asm("sp");*/	\
/*tsb_comp ## key_from[tid].bp = register asm("fp");*/	\
/* x11 hold the base of tsb_comp ## key_from as calculated above */ 	\
	"mov x10, sp\n"	\
/*This is to allow us to store things like ddc, return address */	\
	"sub x10, x10, #32\n"	\ 
	"stp x10, fp, [x11]\n"	\
	/* Now we need to load the dest compartment id into a register and the number of arguments*/	\
/* TODO: tying to load the address of tsb comp for the target may not work, may need to revist this in the future*/	\
	"mov x10, %3\n"	\
	"mov x9, %4\n"	\
	"mov x11, %5\n"	\
	"mov x12, %6\n"	\
	"mov x13, %0\n"	\
	\
	\
	"mov c0, %7\n"	\
	\
	\
	\
	/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
	"ldr c14, [%8]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"(uk_thread_get_tid()), "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from)), "i"(key_to),	"i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(arg1), "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))\
	: "x10", "x11", "x12", "x13", "sp", "x9", "x0"	\
);	\
\
\
\
\
\
__asm__ (	\
	"msr ddc, c29\n"\
	:\
	:\
	:"x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30"\
);\
__asm__ volatile(	\
	"mov x10, %0\n"\
	\
	\
	\
	/* Need to do reentry */	\
/* - Restore stack and frame and tsb*/	\
/* - Pop registers saved */	\
/* restore tsb */ 	\
	"mul x11, x10, %1\n"	\
	"add x11, x11, %2\n"	\
	"ldp x12, fp, [x11]\n"	\
	"mov sp, x12\n"	\
	"ldp x12, x13, [sp, #32]!\n"	\
	"add sp, sp, #16\n"	\
	"stp x12, x13, [x11]\n"\
	"mov x17, sp\n"	\
	"add sp, sp, #448\n"	\
	:\
	:"r"(uk_thread_get_tid()), "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))\
	:"x0", "x8", "x10", "x11", "x12", "x13", "x16", "x18", "x17", "x14", "x15", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x30"\
);\
__asm__ (	\
	"nop\n"\
	:\
	:\
	:"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x30"\
);\
__asm__ (\
	\
	\
	\
	"mov x11, %0\n"\
	"str x0, [x11]\n"	\
	"mov sp, x17\n"	\
	\
	\
	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:	\
	:	"r"(&retval_ptr)	\
	: "x0", "x8", "x10", "x11", "x12", "x13", "x16", "x18", "x17", "x14", "x15", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x30"	\
);	\
__asm__ (	\
	"nop\n"\
	:\
	:\
	:"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x30"\
);\
\
\
\
} while (0)
















#define __flexos_morello_gate2(key_from, key_to, f_ptr, arg1, arg2) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30"							\
);	\
} while (0)

#define __flexos_morello_gate2_r(key_from, key_to, retval_ptr, f_ptr, arg1, arg2)\
do {									\
	/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
\
\
\
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
	"add sp, sp, #256\n"	\
	:				\
	: "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile (	\
	"mov x11, %0\n"\
	"str x0, [x11]\n"	\
	"sub sp, sp, #256\n"	\
	:	\
	:	"r"(&retval_ptr)	\
	: "x0", "x11", "x10"	\
);	\
\
\
\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30", "sp"							\
);	\
} while (0)

















#define __flexos_morello_gate3(key_from, key_to, f_ptr, arg1, arg2, arg3) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30"							\
);	\
} while (0)

#define __flexos_morello_gate3_r(key_from, key_to, retval_ptr, f_ptr, arg1, arg2, arg3)\
do {									\
	/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
\
\
\
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
	"add sp, sp, #256\n"	\
	:				\
	: "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile (	\
	"mov x11, %0\n"\
	"str x0, [x11]\n"	\
	"sub sp, sp, #256\n"	\
	:	\
	:	"r"(&retval_ptr)	\
	: "x0", "x11", "x10"	\
);	\
\
\
\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30", "sp"							\
);	\
} while (0)












#define __flexos_morello_gate4(key_from, key_to, f_ptr, arg1, arg2, arg3, arg4) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	if (IS_CAP(arg4)) {	\
		flexos_morello_move_arg_cap_into_reg(arg4, 4);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg4, 4);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30"							\
);	\
} while (0)

#define __flexos_morello_gate4_r(key_from, key_to, retval_ptr, f_ptr, arg1, arg2, arg3, arg4)\
do {									\
	/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	if (IS_CAP(arg4)) {	\
		flexos_morello_move_arg_cap_into_reg(arg4, 4);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg4, 4);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
\
\
\
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
	"add sp, sp, #256\n"	\
	:				\
	: "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile (	\
	"mov x11, %0\n"\
	"str x0, [x11]\n"	\
	"sub sp, sp, #256\n"	\
	:	\
	:	"r"(&retval_ptr)	\
	: "x0", "x11", "x10"	\
);	\
\
\
\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30", "sp"							\
);	\
} while (0)


















#define __flexos_morello_gate5(key_from, key_to, f_ptr, arg1, arg2, arg3, arg4, arg5) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	if (IS_CAP(arg4)) {	\
		flexos_morello_move_arg_cap_into_reg(arg4, 4);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg4, 4);	\
	}	\
	\
	if (IS_CAP(arg5)) {	\
		flexos_morello_move_arg_cap_into_reg(arg5, 5);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg5, 5);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30"							\
);	\
} while (0)

#define __flexos_morello_gate5_r(key_from, key_to, retval_ptr, f_ptr, arg1, arg2, arg3, arg4, arg5)\
do {									\
	/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	if (IS_CAP(arg4)) {	\
		flexos_morello_move_arg_cap_into_reg(arg4, 4);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg4, 4);	\
	}	\
	\
	if (IS_CAP(arg5)) {	\
		flexos_morello_move_arg_cap_into_reg(arg5, 5);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg5, 5);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
\
\
\
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
	"add sp, sp, #256\n"	\
	:				\
	: "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile (	\
	"mov x11, %0\n"\
	"str x0, [x11]\n"	\
	"sub sp, sp, #256\n"	\
	:	\
	:	"r"(&retval_ptr)	\
	: "x0", "x11", "x10"	\
);	\
\
\
\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30", "sp"							\
);	\
} while (0)













#define __flexos_morello_gate6(key_from, key_to, f_ptr, arg1, arg2, arg3, arg4, arg5, arg6) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	if (IS_CAP(arg4)) {	\
		flexos_morello_move_arg_cap_into_reg(arg4, 4);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg4, 4);	\
	}	\
	\
	if (IS_CAP(arg5)) {	\
		flexos_morello_move_arg_cap_into_reg(arg5, 5);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg5, 5);	\
	}	\
	\
	if (IS_CAP(arg5)) {	\
		flexos_morello_move_arg_cap_into_reg(arg5, 5);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg5, 5);	\
	}	\
	\
	if (IS_CAP(arg6)) {	\
		flexos_morello_move_arg_cap_into_reg(arg6, 6);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg6, 6);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30"							\
);	\
} while (0)

#define __flexos_morello_gate6_r(key_from, key_to, retval_ptr, f_ptr, arg1, arg2, arg3, arg4, arg5, arg6)\
do {									\
	/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	if (IS_CAP(arg4)) {	\
		flexos_morello_move_arg_cap_into_reg(arg4, 4);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg4, 4);	\
	}	\
	\
	if (IS_CAP(arg5)) {	\
		flexos_morello_move_arg_cap_into_reg(arg5, 5);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg5, 5);	\
	}	\
	\
	if (IS_CAP(arg6)) {	\
		flexos_morello_move_arg_cap_into_reg(arg6, 6);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg6, 6);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
\
\
\
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
	"add sp, sp, #256\n"	\
	:				\
	: "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile (	\
	"mov x11, %0\n"\
	"str x0, [x11]\n"	\
	"sub sp, sp, #256\n"	\
	:	\
	:	"r"(&retval_ptr)	\
	: "x0", "x11", "x10"	\
);	\
\
\
\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30", "sp"							\
);	\
} while (0)













#define __flexos_morello_gate7(key_from, key_to, f_ptr, arg1, arg2, arg3, arg4, arg5, arg6, arg7) 		\
do {									\
/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	if (IS_CAP(arg4)) {	\
		flexos_morello_move_arg_cap_into_reg(arg4, 4);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg4, 4);	\
	}	\
	\
	if (IS_CAP(arg5)) {	\
		flexos_morello_move_arg_cap_into_reg(arg5, 5);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg5, 5);	\
	}	\
	\
	if (IS_CAP(arg5)) {	\
		flexos_morello_move_arg_cap_into_reg(arg5, 5);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg5, 5);	\
	}	\
	\
	if (IS_CAP(arg6)) {	\
		flexos_morello_move_arg_cap_into_reg(arg6, 6);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg6, 6);	\
	}	\
	\
	if (IS_CAP(arg7)) {	\
		flexos_morello_move_arg_cap_into_reg(arg7, 7);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg7, 7);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30"							\
);	\
} while (0)

#define __flexos_morello_gate7_r(key_from, key_to, retval_ptr, f_ptr, arg1, arg2, arg3, arg4, arg5, arg6, arg7)\
do {									\
	/* todo \
* - backup registers we need first, come back to this */ \
\
\
	\
__asm__ volatile (	\
	"stp c9, c8, [sp, #-32]!\n"	\
	"stp c10, c11, [sp, #-32]!\n"	\
	"stp c12, c13, [sp, #-32]!\n"	\
	"stp c14, c15, [sp, #-32]!\n"	\
	"stp c0, c1, [sp, #-32]!\n"		\
	"stp c2, c3, [sp, #-32]!\n"		\
	"stp c4, c5, [sp, #-32]!\n"		\
	"stp c6, c7, [sp, #-32]!\n"		\
	"stp c19, c20, [sp, #-32]!\n"		\
	"stp c21, c22, [sp, #-32]!\n"		\
	"stp c23, c24, [sp, #-32]!\n"		\
	"stp c25, c26, [sp, #-32]!\n"		\
	"stp c27, c28, [sp, #-32]!\n"		\
	"stp c29, c30, [sp, #-32]!\n"		\
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
	"mov x10, %0\n"	\
	"mov x9, %1\n"	\
	"mov x11, %2\n"	\
	"mov x12, %3\n"	\
	"mov x13, %4\n"	\
	:				\
	: "i"(key_to), "i"(1), "r"(f_ptr), "r"(tsb_comp ## key_to), "r"(uk_thread_get_tid())	\
	: "x9", "x10", "x11", "x12", "x13"	\
);	\
	\
	\
	\
/* Okay now we need to sort out the args, they need to go in c0-c7 */	\
/* In this case we only have one argument so only need to use c0 */ 	\
	if (IS_CAP(arg1)) {	\
		flexos_morello_move_arg_cap_into_reg(arg1, 1);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg1, 1);	\
	}	\
	\
	if (IS_CAP(arg2)) {	\
		flexos_morello_move_arg_cap_into_reg(arg2, 2);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg2, 2);	\
	}	\
	\
	if (IS_CAP(arg3)) {	\
		flexos_morello_move_arg_cap_into_reg(arg3, 3);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg3, 3);	\
	}	\
	\
	if (IS_CAP(arg4)) {	\
		flexos_morello_move_arg_cap_into_reg(arg4, 4);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg4, 4);	\
	}	\
	\
	if (IS_CAP(arg5)) {	\
		flexos_morello_move_arg_cap_into_reg(arg5, 5);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg5, 5);	\
	}	\
	\
	if (IS_CAP(arg6)) {	\
		flexos_morello_move_arg_cap_into_reg(arg6, 6);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg6, 6);	\
	}	\
	\
	if (IS_CAP(arg7)) {	\
		flexos_morello_move_arg_cap_into_reg(arg7, 7);	\
	} else {	\
		flexos_morello_move_arg_int_into_reg(arg7, 7);	\
	}	\
	\
	\
	\
/* Load the switcher caps and branch to switcher using unsealing instruction ldpblr */	\
__asm__ volatile(	\
	"ldr c14, [%0]\n"	\
	"ldpblr c29, [c14]\n" \
	:				\
	: "r"((uintptr_t *)(&(switcher_call_comp ## key_from)))	\
	: "x11", "c29", "c30", "x9", "x8", "x7", "x6", "x5", "x4", "x3", "x2", "x1", "x0", "x10", "x12", "x13", "x14", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x31"	\
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
\
\
\
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
	"add sp, sp, #256\n"	\
	:				\
	: "r" (sizeof(struct uk_thread_status_block)), "r" ((tsb_comp ## key_from))	\
	: "x10", "x11", "x12", "x13", "sp", "fp", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"	\
);	\
	\
	\
	\
__asm__ volatile (	\
	"mov x11, %0\n"\
	"str x0, [x11]\n"	\
	"sub sp, sp, #256\n"	\
	:	\
	:	"r"(&retval_ptr)	\
	: "x0", "x11", "x10"	\
);	\
\
\
\
__asm__ volatile(	\
	"ldp c29, c30, [sp], #32\n"		\
	"ldp c27, c28, [sp], #32\n"		\
	"ldp c25, c26, [sp], #32\n"		\
	"ldp c23, c24, [sp], #32\n"		\
	"ldp c21, c22, [sp], #32\n"		\
	"ldp c19, c20, [sp], #32\n"		\
	"ldp c6, c7, [sp], #32\n"		\
	"ldp c4, c5, [sp], #32\n"		\
	"ldp c2, c3, [sp], #32\n"		\
	"ldp c0, c1, [sp], #32\n"		\
	"ldp c14, c15, [sp], #32\n"	\
	"ldp c12, c13, [sp], #32\n"	\
	"ldp c10, c11, [sp], #32\n"	\
	"ldp c9, c8, [sp], #32\n"	\
	:								\
	:								\
	: "c18", "c17", "c16", "c15", "c14", "c13",	\
	 "c12", "c11", "c10", "c9", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c19", "c20", "c21", "c22", "c23", "c24", "c25", "c26", "c27", "c28", "c29", "c30", "sp"							\
);	\
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


#define MORELLO_LOAD_SHARED_DATA(ptr_to_load, var_to_put_it_in) \
do { \
	__asm__ (\
	"msr SPSel, #1\n"\
	"ldr x17, [%1]\n"\
	"msr SPSel, #0\n"\
	"str x17, [%0]\n"\
	: \
	: "r"(&var_to_put_it_in), "r"(ptr_to_load)\
	: "memory"\
	);\
} while (0)


#endif
