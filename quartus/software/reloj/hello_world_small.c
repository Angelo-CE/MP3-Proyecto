#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define AUDIO_BASE 0x00011050
#define REG_CONTROL      0
#define REG_FIFO_SPACE   1
#define REG_LEFTDATA     2
#define REG_RIGHTDATA    3

#define PI 3.14159265
#define SAMPLE_RATE 48000
#define DURATION_MS 300
#define AMPLITUDE 300000  // ajusta esto si satura

//Pentatonic de Do
float notes[] = {
    261.63, // C4 (Do)
    293.66, // D4 (Re)
    329.63, // E4 (Mi)
    392.00, // G4 (Sol)
    440.00, // A4 (La)
    523.25, // C5 (Do - siguiente octava)
    587.33, // D5 (Re)
    659.26, // E5 (Mi)
    783.99, // G5 (Sol)
    880.00  // A5 (La)
};

int main() {
    volatile int* audio_ptr = (int*)AUDIO_BASE;
    int fifospace;
    int num_samples = SAMPLE_RATE * DURATION_MS / 1000;

    for (int n = 0; n < sizeof(notes)/sizeof(notes[0]); n++) {
        float freq = notes[n];
        for (int i = 0; i < num_samples; i++) {
            // Espera hasta que haya espacio
            do {
                fifospace = audio_ptr[REG_FIFO_SPACE];
            } while ((fifospace & 0x00FF0000) == 0 || (fifospace & 0xFF000000) == 0);

            // Generar muestra senoidal
            float sample = AMPLITUDE *  freq ;
            int isample = (int)sample;

            // Enviar a ambos canales
            audio_ptr[REG_LEFTDATA] = isample;
            audio_ptr[REG_RIGHTDATA] = isample;
        }
        // Pausa
        usleep(3000);
    }
    return 0;
}

