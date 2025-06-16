#include "playlist.h"
#include <string.h> 
Track playlist[MAX_TRACKS];
int current_track = 0;
int total_tracks = 0;

void init_playlist() {
    // Solo nombres de archivo, sin metadatos complejos
    strncpy(playlist[0].name, "track1.wav", MAX_NAME_LENGTH-1);
    playlist[0].duration_sec = 180;
    
    strncpy(playlist[1].name, "track2.wav", MAX_NAME_LENGTH-1);
    playlist[1].duration_sec = 210;
    
    total_tracks = 2;
}

void next_track() {
    if(total_tracks == 0) return;
    current_track++;
    if(current_track >= total_tracks) current_track = 0;
}

void prev_track() {
    if(total_tracks == 0) return;
    if(current_track == 0) current_track = total_tracks;
    current_track--;
}

// Eliminada la función print_playlist (no necesaria en producción)
