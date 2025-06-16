#include <stddef.h> // Fix NULL
#ifndef HARDWARE_INTERFACE_H
#define HARDWARE_INTERFACE_H

#include <stdint.h>
#include "buttons.h" // Usar el enum Button unificado

void hardware_real_init(void);
void write_leds(uint32_t value);
uint32_t read_buttons(void);
Button get_button_state(void);
void hardware_button_isr(Button btn);
void debug_hardware(void);
void update_display(uint32_t value);
void enable_button_interrupts(void);

#endif
