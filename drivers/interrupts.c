#include "interrupts.h"
#include "minimal_io.h"

static void (*button_callback)(Button) = NULL;

void register_button_handler(void (*handler)(Button)) {
    button_callback = handler;
    if (handler) debug_puts("Manejador de interrupciones registrado\n");
}

#ifdef SIMULATOR
void interrupts_init(void) {}
#else
void interrupts_init(void) {
    // Configura el controlador de interrupciones real
}
#endif

void dispatch_button(Button btn) {
    if (button_callback) button_callback(btn);
}

