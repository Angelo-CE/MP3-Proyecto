#include "state_machine.h"
#include "audio/decoder.h"
#include "drivers/interrupts.h"
#include "drivers/hardware_interface.h"
#include "minimal_io.h"  // Para funciones de debug básico

// Variables globales
PlayerState current_state = IDLE;
volatile int button_event = NO_BUTTON;
extern Track playlist[];
extern int current_track;
extern int total_tracks;

// Manejador de interrupciones para botones
void init_state_machine() {
    current_state = IDLE;
    debug_puts("Maquina de estados inicializada\n");
}

void process_events() {
    if(button_event == NO_BUTTON) return;
    
    switch(button_event) {
        case PLAY_BUTTON:
            handle_play();
            break;
        case PAUSE_BUTTON:
            handle_pause();
            break;
        case STOP_BUTTON:
            handle_stop();
            break;
        case NEXT_BUTTON:
            handle_next();
            break;
        case PREV_BUTTON:
            handle_prev();
            break;
    }
    
    button_event = NO_BUTTON;
}

void handle_play() {
    switch(current_state) {
        case IDLE:
        case PAUSED:
        case STOPPED:
            current_state = PLAYING;
            debug_puts("\nReproduciendo: ");
            debug_puts(playlist[current_track].name);
            debug_puts("\n");
            play_audio(playlist[current_track].name);
            break;
        case PLAYING:
            debug_puts("\nYa esta reproduciendo\n");
            break;
    }
}

void handle_pause() {
    if(current_state == PLAYING) {
        current_state = PAUSED;
        debug_puts("Pausado\n");
        pause_audio();
    }
}

void handle_stop() {
    if(current_state == PLAYING || current_state == PAUSED) {
        current_state = STOPPED;
        debug_puts("Detenido\n");
        stop_audio();
    }
}

void handle_next() {
    if(total_tracks == 0) return;
    
    if(current_state == PLAYING) {
        pause_audio();
    }
    
    next_track();
    debug_puts("\nSiguiente pista: ");
    debug_puts(playlist[current_track].name);
    debug_puts("\n");
    
    if(current_state == PLAYING) {
        play_audio(playlist[current_track].name);
    }
}

void handle_prev() {
    if(total_tracks == 0) return;
    
    if(current_state == PLAYING) {
        pause_audio();
    }
    
    prev_track();
    debug_puts("\nPista anterior: ");
    debug_puts(playlist[current_track].name);
    debug_puts("\n");
    
    if(current_state == PLAYING) {
        play_audio(playlist[current_track].name);
    }
}

const char* get_state_name(PlayerState state) {
    static const char* names[] = {
        "STOPPED", 
        "PLAYING", 
        "PAUSED", 
        "IDLE"
    };
    return (state >= STOPPED && state <= IDLE) ? names[state] : "INVALIDO";
}

void verify_state() {
    if(current_state < STOPPED || current_state > IDLE) {
        debug_puts("Estado invalido! Reiniciando...\n");
        current_state = IDLE;
    }
}
