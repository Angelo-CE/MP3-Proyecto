#include <stddef.h> // Fix NULL
#include "audio_controller.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

// Configuración de audio
#define SAMPLE_RATE 48000
#define AMPLITUDE 800000
#define PI 3.14159265

// Puntero a registros de audio
#ifdef SIMULATOR
static uint32_t simulated_audio_regs[4] = {0};
#else
volatile uint32_t* audio_ptr = (volatile uint32_t*)AUDIO_BASE;
#endif

void audio_init(void) {
#ifdef SIMULATOR
    simulated_audio_regs[REG_FIFO_SPACE] = 0xFFFF0000;
    printf("Audio inicializado (Simulación)\n");
#else
    // Hardware real
    audio_clear_fifos();
    // Usar debug_puts en lugar de printf para bare metal
#endif
}

void audio_write_sample(int32_t left, int32_t right) {
#ifdef SIMULATOR
    // Simulación: mostrar cada 100 muestras
    static int counter = 0;
    if(counter++ % 100 == 0) {
        printf("Audio: L=%-6d R=%-6d\n", left, right);
    }
    simulated_audio_regs[REG_LEFTDATA] = left;
    simulated_audio_regs[REG_RIGHTDATA] = right;
#else
    // Hardware real: esperar espacio en FIFO
    while((audio_read_fifo_space() & 0xFFFF0000) == 0);
    
    audio_ptr[REG_LEFTDATA] = left;
    audio_ptr[REG_RIGHTDATA] = right;
#endif
}

uint32_t audio_read_fifo_space(void) {
#ifdef SIMULATOR
    return simulated_audio_regs[REG_FIFO_SPACE];
#else
    return audio_ptr[REG_FIFO_SPACE];
#endif
}

void audio_clear_fifos(void) {
#ifdef SIMULATOR
    simulated_audio_regs[REG_CONTROL] = 0x300;
    simulated_audio_regs[REG_CONTROL] = 0x000;
#else
    audio_ptr[REG_CONTROL] = 0x300;
    audio_ptr[REG_CONTROL] = 0x000;
#endif
}

// Función de prueba (solo para simulación)
#ifdef SIMULATOR
void generate_tone(float freq, int duration_ms) {
    int samples = SAMPLE_RATE * duration_ms / 1000;
    printf("Generando tono: %.2f Hz (%d muestras)\n", freq, samples);
    
    for(int i = 0; i < samples; i++) {
        float t = (float)i / SAMPLE_RATE;
        int32_t sample = AMPLITUDE * sin(2 * PI * freq * t);
        audio_write_sample(sample, sample);
    }
}
#endif
