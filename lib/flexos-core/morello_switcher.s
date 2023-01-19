#include <flexos/impl/morello.h>

/* 
*   Arguments are expected in registers 0-6 allowing for 7 args
*   Number of arguments should be passed in x7
*   Target compartment ID should be in x8
*   Pointer to target function needs to be in x9
*   tsb_comp_to base addr should be in x13
*   tid in x14
*   DDC should be in c29
*/

.global switch_compartment
.type switch_compartment, "function"
.section compartment_switchers, "ax", %progbits
switch_compartment:

//  Put DDC into the DDC register
    mrs c18, ddc
    stp c18, clr, [sp, #-32]!


    msr ddc, c29

//  size of compartment caps struct
    mov x10, #32

//  get offset of correct compartment to switch to
    mul x10, x10, x8

//  load the ddc for the new compartment
    ldr c12, [x29, x10]

//  load the pcc for the new compartment
    add x10, x10, #16
    ldr c11, [x29, x10]

////////////////////////////////////////////////
// c12 = compartment ddc
// c11 = compartment pcc
////////////////////////////////////////////////

//  set new compartment ddc
    msr ddc, c12

    mov x17, sp
    cvt c18, c18, x17
    scbnds c18, c18, #32
    scvalue c18, c18, x17
    seal c18, c18, lpb

//  size of tsb
    mov x10, #16

//  offset of tsb
    mul x10, x10, x14

//  tsb base
    add x13, x13, x10

//  load sp
    ldr x14, [x13]

//  load fp
    ldr x15, [x13, #8]

//  set new sp and fp
    mov sp, x14
    mov fp, x15

//  branch, we don't want to return
    br c11
    


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
