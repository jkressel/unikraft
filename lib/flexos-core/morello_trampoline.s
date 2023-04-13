.global compartment_trampoline
.type compartment_trampoline, "function"
.section .text
compartment_trampoline:

str c18, [sp, #-16]!
//brnch:
//b brnch
blr x11
//need to handle return values
ldr c18, [sp], #16
ldr x11, [c18]
mov sp, x11
add c18, c18, #8
ldpbr c29, [c18]

.global compartment_trampoline_end
compartment_trampoline_end: