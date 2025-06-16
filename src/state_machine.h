#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <stddef.h>
#include <stdint.h>  // Añadido para uint8_t
#include "buttons.h"

// Definir tipo bool si no existe
#ifndef bool
typedef uint8_t bool;
#define true 1
#define false 0
#endif

#include "playlist.h"

typedef enum {
    STOPPED = 0,
    PLAYING = 1,
    PAUSED = 2,
    IDLE = 3
} PlayerState;

// Variables globales
extern PlayerState current_state;
extern volatile Button button_event;

// Funciones públicas
void init_state_machine(void);
void process_events(void);
void handle_play(void);
void handle_pause(void);
void handle_stop(void);
void handle_next(void);
void handle_prev(void);
const char* get_state_name(PlayerState state);
void verify_state(void);

// Manejador de interrupciones
void button_isr_handler(Button btn);

#endif
