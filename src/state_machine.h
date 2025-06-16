#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "playlist.h"
#include "minimal_io.h"  // Para funciones de debug básico

typedef enum {
    STOPPED = 0,
    PLAYING = 1,
    PAUSED = 2,
    IDLE = 3
} PlayerState;

// Variables globales
extern PlayerState current_state;

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

#endif
