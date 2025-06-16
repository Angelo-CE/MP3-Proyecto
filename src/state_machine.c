// src/state_machine.c
#include "state_machine.h"
#include "audio/decoder.h"
#include "drivers/hardware_interface.h"
#include "minimal_io.h"

// Variables globales
PlayerState    current_state = IDLE;
volatile Button button_event  = NO_BUTTON;
extern Track*  get_current_track(void);
extern int     total_tracks;

// Inicializa y registra el handler
void init_state_machine(void) {
    current_state = IDLE;
    debug_puts("Maquina de estados inicializada\n");
    // Registramos la ISR genérica:
    register_button_handler(button_isr_handler);
}

void button_isr_handler(Button btn) {
    button_event = btn;
}

void process_events(void) {
    if (button_event == NO_BUTTON) return;
    switch (button_event) {
        case PLAY_BUTTON:  handle_play();  break;
        case PAUSE_BUTTON: handle_pause(); break;
        case STOP_BUTTON:  handle_stop();  break;
        case NEXT_BUTTON:  handle_next();  break;
        case PREV_BUTTON:  handle_prev();  break;
        default: break;
    }
    button_event = NO_BUTTON;
}

void handle_play(void) {
    if (current_state != PLAYING) {
        current_state = PLAYING;
        debug_puts("\nReproduciendo: ");
        debug_puts(get_current_track()->name);
        debug_puts("\n");
        play_audio(get_current_track()->name);
    }
}

void handle_pause(void) {
    if (current_state == PLAYING) {
        current_state = PAUSED;
        debug_puts("Pausado\n");
        pause_audio();
    }
}

void handle_stop(void) {
    if (current_state == PLAYING || current_state == PAUSED) {
        current_state = STOPPED;
        debug_puts("Detenido\n");
        stop_audio();
    }
}

void handle_next(void) {
    if (!total_tracks) return;
    if (current_state == PLAYING) pause_audio();
    next_track();
    debug_puts("\nSiguiente pista: ");
    debug_puts(get_current_track()->name);
    debug_puts("\n");
    if (current_state == PLAYING) play_audio(get_current_track()->name);
}

void handle_prev(void) {
    if (!total_tracks) return;
    if (current_state == PLAYING) pause_audio();
    prev_track();
    debug_puts("\nPista anterior: ");
    debug_puts(get_current_track()->name);
    debug_puts("\n");
    if (current_state == PLAYING) play_audio(get_current_track()->name);
}

const char* get_state_name(PlayerState state) {
    static const char* names[] = { "STOPPED", "PLAYING", "PAUSED", "IDLE" };
    return (state <= IDLE) ? names[state] : "INVALIDO";
}

void verify_state(void) {
    if (current_state > IDLE) {
        debug_puts("Estado invalido! Reiniciando...\n");
        current_state = IDLE;
    }
}

