#include <stddef.h> // Fix NULL
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "interrupts.h"

void simulate_button_press(Button button_id);
void simulator_init(void);  // Cambiado de hardware_init a simulator_init

#endif
