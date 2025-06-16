#include "hardware_interface.h"
#include <stdio.h>

// Implementación única de debug_hardware
void debug_hardware(void) {
    printf("\n=== DEBUG HARDWARE ===\n");
    printf("Botones: 0x%08X\n", BUTTONS_BASE);
    printf("LEDs:    0x%08X\n", LEDS_BASE);
    printf("Audio:   0x%08X\n", AUDIO_BASE);
}

Button read_buttons(void) {
    // Implementación simulada
    return NO_BUTTON;
}

void write_leds(uint32_t value) {
    printf("[LEDS] Valor: 0x%lX\n", (unsigned long)value);
}
