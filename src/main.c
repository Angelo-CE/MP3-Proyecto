#include <stdbool.h>
#include "state_machine.h"
#include "playlist.h"
#include "ui.h"
#include "drivers/hardware_interface.h"
#include "drivers/interrupts.h" 

// Estado global
bool running = true;
int current_frame = 0;

// Implementación básica de delay
void delay_ms(unsigned int ms) {
    for (volatile unsigned int i = 0; i < ms * 20000; i++);
}

void init_system() {
    // Inicialización común
    debug_hardware();
    init_playlist();
    init_state_machine();
    hardware_real_init();
}

int main() {
    // 1. Inicialización
    init_system();
    
    // 2. Bucle principal
    while(running) {
        // Actualizar interfaz
        show_playback_status(current_frame);
        
        // Procesar eventos
        process_events();
        
        // Leer botones
        Button btn = read_buttons();
        if(btn != NO_BUTTON) {
            hardware_button_isr(btn);
            delay_ms(200); // Debounce
        }
        delay_ms(100);
        
        // Actualizar tiempo
        if(current_state == PLAYING) {
            current_frame++;
        }
    }

    return 0;
}
