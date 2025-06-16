#include "simulator.h"
#include "interrupts.h"
#include <stdio.h>

void simulator_init() {
    printf("Simulador inicializado\n");
}

void simulate_button_press(Button btn) {
    printf("Botón simulado: %d\n", btn);
    hardware_button_isr(btn);
}
