#include <stddef.h> // Fix NULL
#ifndef UI_H
#define UI_H

#include "state_machine.h"
#include "playlist.h"

// Declaración externa correcta
extern const char* status_icons[];

void show_playback_status(int frame);

#endif
