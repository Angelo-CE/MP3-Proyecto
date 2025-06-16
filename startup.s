.section .vectors, "ax"
    .global _start
_start:
    b reset_handler
    b undef_handler
    b swi_handler
    b prefetch_abort_handler
    b data_abort_handler
    b .
    b irq_handler
    b fiq_handler

reset_handler:
    ldr sp, =_stack_top

    /* Copiar .data a RAM */
    ldr r0, =_data_start
    ldr r1, =_data_end
    ldr r2, =_data_load_start
    cmp r0, r1
    beq data_done
data_loop:
    ldr r3, [r2], #4
    str r3, [r0], #4
    cmp r0, r1
    blo data_loop
data_done:

    /* Inicializar .bss a 0 */
    ldr r0, =_bss_start
    ldr r1, =_bss_end
    mov r2, #0
    cmp r0, r1
    beq bss_done
bss_loop:
    str r2, [r0], #4
    cmp r0, r1
    blo bss_loop
bss_done:

    bl main
    b .

undef_handler: b .
swi_handler: b .
prefetch_abort_handler: b .
data_abort_handler: b .
irq_handler: b .
fiq_handler: b .
