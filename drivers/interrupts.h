#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stddef.h>

typedef enum {
    NO_BUTTON = -1,
    PLAY_BUTTON = 0,
    PAUSE_BUTTON = 1,
    STOP_BUTTON = 2,
    NEXT_BUTTON = 3,
    PREV_BUTTON = 4
} Button;

typedef void (*button_handler_t)(Button);

// Solo declaraciones
void register_button_handler(button_handler_t handler);
void hardware_button_isr(Button button_id);

#endif
