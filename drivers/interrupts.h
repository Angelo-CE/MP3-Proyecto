#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "buttons.h"

void interrupts_init(void);
void register_button_handler(void (*handler)(Button));
// ya no declaramos enable_button_interrupts aquí

// Función para despachar desde la ISR hardware
void dispatch_button(Button btn);

#endif

