#include "interrupts.h"

static button_handler_t current_handler = NULL;

void register_button_handler(button_handler_t handler) {
    current_handler = handler;
}

void hardware_button_isr(Button button_id) {
    if(current_handler != NULL && button_id != NO_BUTTON) {
        current_handler(button_id);
    }
}
