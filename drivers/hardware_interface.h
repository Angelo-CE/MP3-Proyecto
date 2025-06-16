#ifndef HARDWARE_INTERFACE_H
#define HARDWARE_INTERFACE_H

#include <stdint.h>
#include "interrupts.h"  // Para Button

// Direcciones base
#define BUTTONS_BASE 0x00011020
#define LEDS_BASE    0x00011030
#define AUDIO_BASE   0x00011050

// Prototipos
Button read_buttons(void);
void write_leds(uint32_t value);
void debug_hardware(void);

#ifdef SIMULATOR
void simulator_init(void);
#else
void hardware_real_init(void);
#endif

#endif
