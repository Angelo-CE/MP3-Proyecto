#include "state_machine.h"
#include <stdio.h>
#include <stdlib.h>
#include "../audio/decoder.h"
#include "../drivers/interrupts.h"
#include "../drivers/hardware_interface.h"

// Variables globales
PlayerState current_state = IDLE;
volatile int button_event = NO_BUTTON;
extern Track playlist[];
extern int current_track;
extern int total_tracks;

// Manejador de interrupciones para botones

void init_state_machine() {
    
    current_state = IDLE;
    printf("Máquina de estados inicializada\n");
}

void process_events() {
    if(button_event == NO_BUTTON) return;
    
    
    button_event = NO_BUTTON;
}

void handle_play() {
    switch(current_state) {
        case IDLE:
        case PAUSED:
        case STOPPED:
            current_state = PLAYING;
            printf("\nReproduciendo: %s\n", playlist[current_track].name);
            play_audio(playlist[current_track].name);
            break;
        case PLAYING:
            printf("\nYa está reproduciendo\n");
            break;
    }
}

void handle_pause() {
    if(current_state == PLAYING) {
        current_state = PAUSED;
        printf("Pausado\n");
        pause_audio();
    }
}

void handle_stop() {
    if(current_state == PLAYING || current_state == PAUSED) {
        current_state = STOPPED;
        printf("Detenido\n");
        stop_audio();
        
        #ifdef SIMULATOR
        printf("(Simulación) Transición a IDLE después de 5s\n");
        #endif
    }
}

void handle_next() {
    if(total_tracks == 0) return;
    
    if(current_state == PLAYING) {
        pause_audio();
    }
    
    next_track();
    printf("\n▶ Siguiente pista: %s\n", playlist[current_track].name);
    
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
    printf("\n◀ Pista anterior: %s\n", playlist[current_track].name);
    
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
        fprintf(stderr, "⚠️ Estado inválido %d! Reiniciando...\n", current_state);
        current_state = IDLE;
    }
}
