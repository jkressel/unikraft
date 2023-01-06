#include <flexos/impl/morello.h>
#include <flexos/impl/morello-impl.h>

#include <stdint.h>
#include <stddef.h>
#include <assert.h>

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

struct uk_thread_status_block tsb_comp1[32]  __attribute__((section(".data_comp1"))) __attribute__((used));


#define	cheri_setbounds(x, y)	__builtin_cheri_bounds_set((x), (y))
#define	cheri_andperm(x, y)	__builtin_cheri_perms_and((x), (y))
#define	cheri_setaddress(x, y)	__builtin_cheri_address_set((x), (y))

extern char switch_compartment[];
extern char switch_compartment_end[];
extern char _compartment_caps_start[], _compartment_caps_end[];
extern char _text[], _etext[];
extern char compartment_trampoline[];
extern char compartment_trampoline_end[];

void *__capability switcher_capabilities[NUMBER_OF_COMPARTMENTS];

void *__capability switcher_call;

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
   assert((uintptr_t)(&switcher_capabilities) % 16 == 0);
	void *__capability switch_cap = (void *__capability) switch_compartment;
	size_t switcher_size = (uintptr_t) switch_compartment_end - (uintptr_t) switch_compartment;
	switch_cap = cheri_setbounds(switch_cap, switcher_size);
	switcher_capabilities[1] = switch_cap;

	void *__capability comps_addr = (void *__capability) _compartment_caps_start;
    size_t caps_size = (uintptr_t) _compartment_caps_end - (uintptr_t) _compartment_caps_start;
	//possibly need to check this is the right size if something is going wrong
	comps_addr = cheri_setbounds(comps_addr, (uintptr_t)(caps_size));
	switcher_capabilities[0] = comps_addr;

	switcher_call = (void *__capability) switcher_capabilities;
	//Seal this capability to be only used via a `lpb` type call
	asm("seal %w0, %w0, lpb" : "+r"(switcher_call) :);

	__flexos_morello_gate1(0,1,1,0);
}

// okay then no need to be so mean about my hard work here :(

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
	//assert(id < COMP_COUNT);
	struct comp new_comp;
	new_comp.id = compartment_id;

	// Ensure 16-byte alignment throught the compartment bounds
	//assert(((uintptr_t) new_comp.compartment_start) % 16 == 0);
	//assert(((uintptr_t) new_comp.stack_addr) % 16 == 0);
	//assert(total_comp_size % 16 == 0);

	// When creating a compartment, store a local copy of the capability which
	// will allow us to call `switch_compartment` in the heap of the compartment.

	//This is for the DDC (data capability)
	void *__capability comp_ddc = (void *__capability) _start_addr;
	size_t comp_ddc_size = (uintptr_t) _end_addr - (uintptr_t) _start_addr;
	comp_ddc = cheri_setbounds(comp_ddc, (uintptr_t)comp_ddc_size);
    comp_ddc = cheri_andperm(comp_ddc, DEFAULT_CAPS);
	new_comp.ddc = comp_ddc;

	// Set up a capability pointing to the function we want to call within the
	// compartment. This will be loaded as the PCC when the function is called.
	void *__capability comp_fn = (void *__capability) _text;
	size_t comp_fn_size = (uintptr_t) _etext - (uintptr_t) comp_fn;
	comp_fn = cheri_setbounds(comp_fn, comp_fn_size);
    comp_fn = cheri_setaddress(comp_fn, (uintptr_t)compartment_trampoline);
    comp_fn = cheri_andperm(comp_fn, DEFAULT_CAPS);
	new_comp.comp_fn = comp_fn;

	compartments[compartment_id] = new_comp;
	++compartment_id;
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