.section .reset, "ax"
.global _start
_start:
    ldr sp, =_stack_top  // Inicializar pila
    bl main               // Llamar a main()
    b .                   // Loop infinito si main retorna
