#include <stddef.h> // Fix NULL
#include <stdint.h>
#include "state_machine.h"
#include "playlist.h"
#include "ui.h"
#include "drivers/hardware_interface.h"
#include "drivers/interrupts.h"

// Variables globales
bool running = true;
int current_frame = 0;

void init_system() {
    init_playlist();
    init_state_machine();
    interrupts_init();
}

int main() {
    init_system();
    
    while(running) {
        show_playback_status(current_frame);
        
        // Solo usar WFI en hardware real
        #ifndef SIMULATOR
        __asm__("wfi");
        #endif
        
        if(current_state == PLAYING) {
            current_frame++;
        }
    }

    return 0;
}
