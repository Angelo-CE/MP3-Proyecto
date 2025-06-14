#include "simulator.h"

typedef enum {
    PLAY_BUTTON,
    NEXT_BUTTON,
    PREV_BUTTON
} Button;

int button_pressed(Button btn) {
    // Lógica real iría aquí
    return (btn == PLAY_BUTTON); // Simula que solo PLAY funciona
}
