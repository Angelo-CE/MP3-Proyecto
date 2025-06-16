#ifndef AUDIO_CONTROLLER_H
#define AUDIO_CONTROLLER_H

#include <stdint.h>

#define AUDIO_BASE 0x00011050

typedef enum {
    REG_CONTROL = 0,
    REG_FIFO_SPACE = 1,
    REG_LEFTDATA = 2,
    REG_RIGHTDATA = 3
} AudioRegisters;

void audio_init(void);
void audio_write_sample(int32_t left, int32_t right);
uint32_t audio_read_fifo_space(void);
void audio_clear_fifos(void);
void generate_tone(float freq, int duration_ms);

#endif
