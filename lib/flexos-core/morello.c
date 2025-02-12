#include <flexos/impl/morello.h>
#include <flexos/impl/morello-impl.h>

#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdio.h>

struct uk_alloc *allocators[NUMBER_OF_COMPARTMENTS];
uint64_t stacks[NUMBER_OF_COMPARTMENTS];

//this contains the compartment struct for each compartment, this includes the compartment capabilites
//which is why it is in .compartment_caps
struct comp compartments[NUMBER_OF_COMPARTMENTS] __attribute__((section(".compartment_caps"))) __attribute__((used));

/* Mark it "used" as it might potentially only be used in inline assembly */
struct uk_thread_status_block tsb_comp0[32] __attribute__((used));
/* The toolchain will insert TSB declarations here, e.g.:
 *
 * struct uk_thread_status_block tsb_comp1[32] __section(".data_comp1");
 *
 * for compartment 1.
 */

/* __FLEXOS MARKER__: insert tsb decls here. */


extern char switch_compartment[];
extern char switch_compartment_end[];
extern char _compartment_caps_start[], _compartment_caps_end[];
extern char _text[], _etext[];
extern char compartment_trampoline[];
extern char compartment_trampoline_end[];

#define morello_create_capability_with_addr_from_ptr(ptr, size, store_to_ptr)	\
	__asm__ volatile(	\
		"cvtp c0, %0\n"	\
		"scbnds c0, c0, %2\n"	\
		"scvalue c0, c0, %3\n"	\
		"mov x1, #(1<<1) \n"	\
		"clrperm c0, c0, x1\n"	\
		"str c0, [%1]\n"	\
		:	\
		: "r"((uintptr_t *)(ptr)), "r"((uintptr_t *)(store_to_ptr)), "r"(size), "r"(compartment_trampoline)	\
		: "c0", "x1", "memory"	\
	)

struct morello_compartment_switcher_caps switcher_capabilities;

//TODO Morello replace
void *__capability switcher_call_comp0;

/* __FLEXOS MARKER__: insert switcher calls here. */

uint64_t compartment_id = 0;

int get_compartment_id() {
    int id;
     __asm__ (                                           
        "mrs        c17, CID_EL0\n"
        "str        x17, %0\n"                        
        : "+m" (id)
        :                        
        : "memory", "c17"  
    ); 
    return id;
}

void init_compartments()
{
	printf("got to init comps\n");
   	assert((uintptr_t)(&switcher_capabilities) % 16 == 0);
	uintptr_t switcher_size = (uintptr_t) switch_compartment_end - (uintptr_t) switch_compartment;
	morello_create_capability_from_ptr(((uintptr_t)switch_compartment), switcher_size, ((uintptr_t *)(&(switcher_capabilities.pcc))));

    size_t caps_size = (uintptr_t) _compartment_caps_end - (uintptr_t) _compartment_caps_start;
//	morello_create_capability_from_ptr(((uintptr_t)_compartment_caps_start), caps_size, ((uintptr_t *)(&(switcher_capabilities.ddc))));
	morello_create_capability_from_ptr(((uintptr_t)compartments), sizeof(compartments), ((uintptr_t *)(&(switcher_capabilities.ddc))));

	assert((uintptr_t)(&switcher_call_comp0) % 16 == 0);

	morello_create_capability_from_ptr((uintptr_t *)(&(switcher_capabilities)), sizeof(switcher_capabilities), ((uintptr_t *)(&(switcher_call_comp0))));
	/* __FLEXOS MARKER__: insert create switcher calls here. */

	//Seal this capability to be only used via a `lpb` type call
	asm("seal %w0, %w0, lpb" : "+r"(switcher_call_comp0) :);
	/* __FLEXOS MARKER__: insert seal switcher calls here. */

	printf("got to end of init comps\n");

}

// This is what is needed for a compartment to be fully initialised
// 1. DDC needs to encompass the compartment data and bss section
// 2. PCC needs to point to the general text section for now, in the future, a compartment text may split off
// 3. Store these in a compartment caps section

// void add_compartment(int id, ) {
// 	struct comp new_comp;
// 	new_comp.id = id;
// }

void add_comp(uint64_t _start_addr, uint64_t _end_addr)
{
	assert(compartment_id < NUMBER_OF_COMPARTMENTS);
	struct comp new_comp;
//	new_comp.id = compartment_id;

//	assert((uintptr_t)(&switcher_capabilities) % 16 == 0);

	//This is for the DDC
	size_t comp_ddc_size = (uintptr_t) _end_addr - (uintptr_t) _start_addr;
	morello_create_capability_from_ptr((uintptr_t *)(_start_addr), comp_ddc_size, ((uintptr_t *)(&(new_comp.ddc))));
	printf("Start: 0x%x, End: 0x%x\n", _start_addr, _end_addr);

	// Set up a capability pointing to the function we want to call within the
	// compartment. This will be loaded as the PCC when the function is called.
	size_t comp_text_size = (uintptr_t) _etext - (uintptr_t) _text;
	morello_create_capability_with_addr_from_ptr((uintptr_t *)(_text), comp_text_size, ((uintptr_t *)(&(new_comp.pcc))));

	compartments[compartment_id] = new_comp;
	++compartment_id;
}

void test_things() {
	//__flexos_morello_gate1(0,1,1,switcher_call_comp0);
	printf("tsb 1 thread 0, sp: 0x%x\n", tsb_comp1[0].sp);
	printf("tsb 1 thread 1, sp: 0x%x\n", tsb_comp1[1].sp);	
	printf("tsb 0 thread 0, sp: 0x%x\n", tsb_comp0[0].sp);
	printf("tsb 0 thread 1, sp: 0x%x\n", tsb_comp0[1].sp);	

}

struct uk_alloc *get_alloc(int compartment_id) {
	/* TODO Morello - surprise there's no replacement, just a giant stinking turd insead hahaha */
	//Please for the love of the all that is good in the world add some bounds checking
	if (compartment_id < NUMBER_OF_COMPARTMENTS) {
		return allocators[compartment_id];
	} else {
		return NULL;
	}

}

void morello_enter_main(void (*_comp_fn)()) {
	__asm__ volatile (
		"mov c10, %1\n"
		"ldr x11, =(cont)\n"
		"scvalue c10, c10, x11\n"
		"mov x11, #(1<<1)\n"
		"clrperm c10, c10, x11\n"
		"mov c11, %2\n"
		"mov x9, sp\n"
		"brr c10\n"
		"cont: msr ddc, c11\n"
		"mov sp, x9\n"
		" mov x9, %0\n"
		"blr x9\n"
		:
		: "r"(_comp_fn), "r"(compartments[0].pcc), "r"(compartments[0].ddc) 
		: "c10", "c11", "x9"
	);
}
