#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stddef.h> // Fix NULL

#define MAX_TRACKS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    char album[MAX_NAME_LENGTH];
    int  duration;  // duración en segundos
} Track;

extern Track playlist[MAX_TRACKS];
extern int   current_track;
extern int   total_tracks;

void init_playlist(void);
void next_track(void);
void prev_track(void);
// Ahora devuelve puntero para evitar struct-return y memcpy
Track* get_current_track(void);

#endif

