#include "playlist.h"
#include <stdio.h>
#include <string.h>

Track playlist[MAX_TRACKS];
int current_track = 0;
int total_tracks = 0;

void init_playlist() {
    strncpy(playlist[0].name, "track1.wav", MAX_NAME_LENGTH-1);
    playlist[0].duration_sec = 180;
    
    strncpy(playlist[1].name, "track2.wav", MAX_NAME_LENGTH-1);
    playlist[1].duration_sec = 210;
    
    total_tracks = 2;
}

void next_track() {
    if(total_tracks == 0) return;
    current_track = (current_track + 1) % total_tracks;
}

void prev_track() {
    if(total_tracks == 0) return;
    current_track = (current_track - 1 + total_tracks) % total_tracks;
}

void print_playlist() {
    if(total_tracks == 0 || current_track < 0 || current_track >= total_tracks) {
        fprintf(stderr, " Playlist no inicializada\n");
        return;
    }

    printf("\n=== PLAYLIST ===\n");
    for(int i=0; i<total_tracks; i++) {
        printf("%d. %s (%d:%02d) %s\n", 
               i+1, 
               playlist[i].name,
               playlist[i].duration_sec/60,
               playlist[i].duration_sec%60,
               (i==current_track) ? "[ACTUAL]" : "");
    }
}
