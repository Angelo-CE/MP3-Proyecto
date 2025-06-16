#include "hardware_interface.h"
#include "minimal_io.h"
#include "interrupts.h"  // Para dispatch_button

// Direcciones base de hardware
#define BUTTONS_BASE  0xFF200000
#define LEDS_BASE     0xFF200020
#define DISPLAY_BASE  0xFF200030

// Registros mapeados en memoria
volatile uint32_t* const buttons = (volatile uint32_t*)BUTTONS_BASE;
volatile uint32_t* const leds = (volatile uint32_t*)LEDS_BASE;
volatile uint32_t* const display = (volatile uint32_t*)DISPLAY_BASE;

#ifdef SIMULATOR
#include <stdio.h>
#endif

// Escribe un valor en los LEDs
void write_leds(uint32_t value) {
    *leds = value;
    
    #ifdef SIMULATOR
    char msg[50];
    snprintf(msg, sizeof(msg), "LEDs: 0x%08X", (unsigned int)value);
    debug_puts(msg);
    #else
    debug_puts("LEDs: 0x");
    debug_putint(value);
    debug_puts("\n");
    #endif
}

// Lee el estado de los botones
uint32_t read_buttons(void) {
    return *buttons;
}

// Actualiza el display de 7 segmentos
void update_display(uint32_t value) {
    *display = value;
    
    #ifdef SIMULATOR
    char msg[50];
    snprintf(msg, sizeof(msg), "Display: %d", (unsigned int)value);
    debug_puts(msg);
    #else
    debug_puts("Display: ");
    debug_putint(value);
    debug_puts("\n");
    #endif
}

// Inicialización de hardware
void hardware_real_init(void) {
    // Inicializar periféricos
    *leds = 0;     // Apagar todos los LEDs
    *display = 0;  // Apagar display
    
    #ifdef SIMULATOR
    debug_puts("Hardware inicializado (Simulación)\n");
    #else
    debug_puts("Hardware inicializado (Bare Metal)\n");
    #endif
}

// Función de depuración
void debug_hardware(void) {
    uint32_t state = read_buttons();
    
    #ifdef SIMULATOR
    char msg[50];
    snprintf(msg, sizeof(msg), "Botones: 0x%08X", (unsigned int)state);
    debug_puts(msg);
    #else
    debug_puts("Botones: 0x");
    debug_putint(state);
    debug_puts("\n");
    #endif
}

// Obtiene el estado de los botones
Button get_button_state(void) {
    uint32_t state = read_buttons();
    
    // Mapear bits a botones específicos
    if (state & 0x1)  return PLAY_BUTTON;
    if (state & 0x2)  return PAUSE_BUTTON;
    if (state & 0x4)  return STOP_BUTTON;
    if (state & 0x8)  return NEXT_BUTTON;
    if (state & 0x10) return PREV_BUTTON;
    if (state & 0x20) return VOL_UP_BUTTON;
    if (state & 0x40) return VOL_DOWN_BUTTON;
    
    return NO_BUTTON;
}

// Manejador de interrupción de botones
void hardware_button_isr(Button btn) {
    #ifdef SIMULATOR
    const char* btn_name;
    switch(btn) {
        case PLAY_BUTTON:    btn_name = "PLAY";    break;
        case PAUSE_BUTTON:   btn_name = "PAUSE";   break;
        case STOP_BUTTON:    btn_name = "STOP";    break;
        case NEXT_BUTTON:    btn_name = "NEXT";    break;
        case PREV_BUTTON:    btn_name = "PREV";    break;
        case VOL_UP_BUTTON:  btn_name = "VOL_UP";  break;
        case VOL_DOWN_BUTTON:btn_name = "VOL_DOWN";break;
        default:             btn_name = "UNKNOWN"; break;
    }
    debug_puts("Interrupción de botón: ");
    debug_puts(btn_name);
    debug_puts("\n");
    #else
    // En hardware real, despacha al callback registrado
    dispatch_button(btn);
    #endif
}

// Habilita las interrupciones de botones
void enable_button_interrupts(void) {
    #ifdef SIMULATOR
    debug_puts("Interrupciones de botones habilitadas (simulación)\n");
    #else
    // Configurar registros de interrupción
    *buttons |= 0x7F; // Habilitar interrupciones para los primeros 7 botones
    debug_puts("Interrupciones de botones habilitadas\n");
    #endif
}

