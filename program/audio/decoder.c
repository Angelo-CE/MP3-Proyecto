#include "decoder.h"
#include "audio_controller.h"
#include <stdio.h>

#ifdef SIMULATOR
void play_audio(const char* filename) {
    printf("Simulando: %s\n", filename);
    generate_tone(440.0, 1000);
}
#else
#include "sd_card.h"

void transfer_to_fpga(uint8_t* data, size_t size) {
    // Implementación temporal
    for(size_t i = 0; i < size; i += 4) {
        int32_t sample = *(int32_t*)&data[i];
        audio_write_sample(sample, sample);
    }
}

void play_audio(const char* filename) {
    uint8_t buffer[512];
    int size = sd_get_filesize(filename);
    int sectors = size / 512;
    
    for(int i = 0; i < sectors; i++) {
        if(sd_read(buffer, i) != 0) break;
        transfer_to_fpga(buffer, 512);
    }
}
#endif

void pause_audio(void) {
    printf("Audio pausado\n");
}

void stop_audio(void) {
    printf("Audio detenido\n");
    audio_clear_fifos();
}
