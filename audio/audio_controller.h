#include <stddef.h> // Fix NULL
#ifndef AUDIO_CONTROLLER_H
#define AUDIO_CONTROLLER_H

#include <stdint.h>

// Definición condicional para evitar conflictos
#ifndef AUDIO_BASE
#define AUDIO_BASE 0x00011050  // Valor por defecto para simulación
#endif

typedef enum {
    REG_CONTROL = 0,
    REG_FIFO_SPACE = 1,
    REG_LEFTDATA = 2,
    REG_RIGHTDATA = 3
} AudioRegisters;

// Prototipos de funciones
void audio_init(void);
void audio_write_sample(int32_t left, int32_t right);
uint32_t audio_read_fifo_space(void);
void audio_clear_fifos(void);

// Función solo para simulación
#ifdef SIMULATOR
void generate_tone(float freq, int duration_ms);
#endif

#endif
