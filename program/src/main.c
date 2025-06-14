#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "state_machine.h"
#include "playlist.h"
#include "ui.h"
#include "drivers/hardware_interface.h"
#include "drivers/simulator.h"
#include "drivers/interrupts.h" 

// Configuración de simulación
#define SIMULATION_ITERATIONS 100
#define SIMULATION_DELAY_US 50000  // 50ms

// Estado global
bool running = true;
int current_frame = 0;
int sim_counter = 0;

void sigint_handler(int sig) {
    running = false;
    printf("\nInterrupción recibida, terminando...\n");
}

void simulate_sequence() {
    sim_counter++;
    
    switch(sim_counter) {
        case 20:
            printf("\n[SIM] Botón PAUSE presionado\n");
            hardware_button_isr(PAUSE_BUTTON);
            break;
        case 40:
            printf("\n[SIM] Botón PLAY presionado\n");
            hardware_button_isr(PLAY_BUTTON);
            break;
        case 60:
            printf("\n[SIM] Botón NEXT presionado\n");
            hardware_button_isr(NEXT_BUTTON);
            break;
        case 80:
            printf("\n[SIM] Botón STOP presionado\n");
            hardware_button_isr(STOP_BUTTON);
            break;
        case SIMULATION_ITERATIONS:
            running = false;
            printf("\n[SIM] Simulación completada\n");
            break;
    }
}

void init_system() {
    // Inicialización común
    debug_hardware();
    init_playlist();
    init_state_machine();

    // Inicialización específica del modo
    #ifdef SIMULATOR
    simulator_init();
    printf("\n=== MODO SIMULACIÓN ===\n");
    #else
    hardware_real_init();
    printf("\n=== MODO HARDWARE ===\n");
    #endif
}

int main() {
    signal(SIGINT, sigint_handler);
    
    // 1. Inicialización
    init_system();
    
    // 2. Secuencia automática (solo simulación)
    #ifdef SIMULATOR
    printf("Secuencia automática:\n");
    printf("0s:PLAY | 2s:PAUSE | 4s:PLAY | 6s:NEXT | 8s:STOP\n");
    hardware_button_isr(PLAY_BUTTON);
    #endif

    // 3. Bucle principal
    while(running) {
        // Actualizar interfaz
        show_playback_status(current_frame);
        
        // Procesar eventos
        process_events();
        
        #ifdef SIMULATOR
        simulate_sequence();
        usleep(SIMULATION_DELAY_US);
        
        // Mostrar playlist cada segundo
        if(sim_counter % (1000000/SIMULATION_DELAY_US) == 0) {
            print_playlist();
        }
        #else
        // Lógica para hardware real
        Button btn = read_buttons();
        if(btn != NO_BUTTON) {
            hardware_button_isr(btn);
            usleep(200000); // Debounce
        }
        usleep(100000);
        #endif
        
        // Actualizar tiempo
        if(current_state == PLAYING) {
            current_frame++;
        }
    }

    printf("\nSistema terminado correctamente\n");
    return 0;
}
