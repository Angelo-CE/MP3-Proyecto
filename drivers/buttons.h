#include <stddef.h> // Fix NULL
#ifndef BUTTONS_H
#define BUTTONS_H

typedef enum {
    NO_BUTTON = -1,
    PLAY_BUTTON,
    PAUSE_BUTTON,
    STOP_BUTTON,
    NEXT_BUTTON,
    PREV_BUTTON,
    VOL_UP_BUTTON,
    VOL_DOWN_BUTTON
} Button;

#endif
