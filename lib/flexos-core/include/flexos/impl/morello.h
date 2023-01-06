#ifndef FLEXOS_MORELLO_H
#define FLEXOS_MORELLO_H

#include <stdint.h>

struct uk_alloc;

// TODO Morello Replace
#define NUMBER_OF_COMPARTMENTS 2

/* Dynamic allocator for compartment 1 */

int get_compartment_id();
void init_compartments();
void add_comp(uint64_t _start_addr, uint64_t _end_addr);
struct uk_alloc *get_alloc(int compartment_id);

extern struct uk_alloc *allocators[NUMBER_OF_COMPARTMENTS];
extern uint64_t stacks[NUMBER_OF_COMPARTMENTS];

struct uk_thread_status_block {
	uint64_t sp;
	uint64_t bp;
};


//TODO Morello Replace
extern struct uk_thread_status_block tsb_comp0[32];
extern struct uk_thread_status_block tsb_comp1[32];


struct comp
{
	uint64_t id;
	void *__capability ddc;
	void *__capability comp_fn;
};

extern struct comp compartments[NUMBER_OF_COMPARTMENTS];


/*
 * CHERI ISA-defined constants for capabilities -- suitable for inclusion from
 * assembly source code.
 * Taken from cheribsd
 */
#define	CHERI_PERM_GLOBAL			(1 << 0)	/* 0x00000001 */
#define	CHERI_PERM_EXECUTIVE			(1 << 1)	/* 0x00000002 */
#define	CHERI_PERM_SW0				(1 << 2)	/* 0x00000004 */
#define	CHERI_PERM_SW1				(1 << 3)	/* 0x00000008 */
#define	CHERI_PERM_SW2				(1 << 4)	/* 0x00000010 */
#define	CHERI_PERM_SW3				(1 << 5)	/* 0x00000020 */
#define	CHERI_PERM_MUTABLE_LOAD			(1 << 6)	/* 0x00000040 */
#define	CHERI_PERM_COMPARTMENT_ID		(1 << 7)	/* 0x00000080 */
#define	CHERI_PERM_BRANCH_SEALED_PAIR		(1 << 8)	/* 0x00000100 */
#define	CHERI_PERM_CCALL			CHERI_PERM_BRANCH_SEALED_PAIR
#define	CHERI_PERM_SYSTEM			(1 << 9)	/* 0x00000200 */
#define	CHERI_PERM_SYSTEM_REGS			CHERI_PERM_SYSTEM
#define	CHERI_PERM_UNSEAL			(1 << 10)	/* 0x00000400 */
#define	CHERI_PERM_SEAL				(1 << 11)	/* 0x00000800 */
#define	CHERI_PERM_STORE_LOCAL_CAP		(1 << 12)	/* 0x00001000 */
#define	CHERI_PERM_STORE_CAP			(1 << 13)	/* 0x00002000 */
#define	CHERI_PERM_LOAD_CAP			(1 << 14)	/* 0x00004000 */
#define	CHERI_PERM_EXECUTE			(1 << 15)	/* 0x00008000 */
#define	CHERI_PERM_STORE			(1 << 16)	/* 0x00010000 */
#define	CHERI_PERM_LOAD				(1 << 17)	/* 0x00020000 */



//Default permissions given to a capability
#define DEFAULT_CAPS (CHERI_PERM_LOAD|CHERI_PERM_STORE|CHERI_PERM_EXECUTE|CHERI_PERM_LOAD_CAP|CHERI_PERM_STORE_CAP|CHERI_PERM_STORE_LOCAL_CAP|CHERI_PERM_BRANCH_SEALED_PAIR|CHERI_PERM_MUTABLE_LOAD|CHERI_PERM_GLOBAL|CHERI_PERM_EXECUTIVE)



#endif