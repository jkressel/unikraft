#include <flexos/impl/morello.h>

/* 
*   Arguments are expected in registers 0-7 allowing for 8 args
*   Indirect return pointer in x8
*   Number of arguments should be passed in x9
*   Target compartment ID should be in x10
*   Pointer to target function needs to be in x11
*   tsb_comp_to base addr should be in x12
*   tid in x13
*   DDC should be in c29
*/

.global switch_compartment
.type switch_compartment, "function"
.section compartment_switchers, "ax", %progbits
switch_compartment:

//  Put DDC into the DDC register
    mrs c18, ddc
    stp c18, clr, [sp, #-32]!
    mov x17, sp
    add x17, x17, #32
    str x17, [sp, #-8]!


    msr ddc, c29

//  size of compartment caps struct
    mov x14, #32

//  get offset of correct compartment to switch to
    mul x14, x14, x10

//  load the ddc for the new compartment
    ldr c15, [x29, x14]

//  load the pcc for the new compartment
    add x14, x14, #16
    ldr c16, [x29, x14]

////////////////////////////////////////////////
// c15 = compartment ddc
// c16 = compartment pcc
////////////////////////////////////////////////

//  set new compartment ddc
    msr ddc, c15

    mov x17, sp
    cvt c18, c18, x17
    scbnds c18, c18, #40
    scvalue c18, c18, x17
//    seal c18, c18, lpb

//  size of tsb
    mov x14, #16

//  offset of tsb
    mul x14, x14, x13

//  tsb base
    add x12, x12, x14

//  load sp
    ldr x14, [x12]

//  load fp
    ldr x15, [x12, #8]

//  set new sp and fp
    mov sp, x14
    mov fp, x15

//  branch, we don't want to return
    br c16
    


//Need to preserve x19-x29

clean_call:
    mov x0, #0
    mov x1, #0
    mov x2, #0
    mov x3, #0
    mov x4, #0
    mov x5, #0
    mov x6, #0
    mov x7, #0
    mov x8, #0
    mov x9, #0
    mov x10, #0
   // mov x11, #0
    mov x12, #0
    mov x13, #0
    mov x15, #0
    mov x16, #0
    mov x17, #0
    mov x18, x18
    mov x19, x19
    mov x20, x20
    mov x21, x21
    mov x22, x22
    mov x23, x23
    mov x24, x24
    mov x25, x25
    mov x26, x26
    mov x27, x27
    mov x28, x28
    mov x29, x29
    ret

clean_ret:
    mov x0, #0
    mov x1, #0
    mov x2, #0
    mov x3, #0
    mov x4, #0
    mov x5, #0
    mov x6, #0
    mov x7, #0
    mov x8, #0
    mov x9, #0
    mov x10, #0
    mov x11, #0
    mov x12, #0
    mov x13, #0
    mov x14, #0
    mov x15, #0
    mov x16, #0
    mov x17, #0
    mov x18, x18
    mov x19, x19
    mov x20, x20
    mov x21, x21
    mov x22, x22
    mov x23, x23
    mov x24, x24
    mov x25, x25
    mov x26, x26
    mov x27, x27
    mov x28, x28
    mov x29, x29
    ret
.global switch_compartment_end
switch_compartment_end:
