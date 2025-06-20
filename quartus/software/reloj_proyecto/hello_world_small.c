#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#define AUDIO_BASE       0x00011050
#define RAM_SHARED_BASE  0x00040000

#define REG_CONTROL      0
#define REG_FIFO_SPACE   1
#define REG_LEFTDATA     2
#define REG_RIGHTDATA    3

int main() {
    volatile int* audio_ptr = (int*)AUDIO_BASE;
    volatile int16_t* ram_ptr = (int16_t*)RAM_SHARED_BASE;

    int i;
    int fifospace;

    for (i = 0; i < 48000; i++) {
        do {
            fifospace = audio_ptr[REG_FIFO_SPACE];
        } while ((fifospace & 0x00FF0000) == 0 || (fifospace & 0xFF000000) == 0);

        int16_t sample = ram_ptr[i];
        audio_ptr[REG_LEFTDATA] = sample;
        audio_ptr[REG_RIGHTDATA] = sample;
    }

    return 0;
}
