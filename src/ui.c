#include "ui.h"
#include "state_machine.h"
#include "playlist.h"
#include <stdio.h>

const char* status_icons[] = {
    "⏹",  // STOPPED
    "⏵",  // PLAYING
    "⏸",  // PAUSED
    "💤"   // IDLE
};

void show_playback_status(int frame) {
    printf("\r%s %s (%d:%02d/%d:%02d) [%s]", 
           status_icons[current_state],
           playlist[current_track].name,
           frame/60, frame%60,
           playlist[current_track].duration_sec/60,
           playlist[current_track].duration_sec%60,
           get_state_name(current_state));
    fflush(stdout);
}
