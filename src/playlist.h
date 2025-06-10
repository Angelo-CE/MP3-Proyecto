#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_TRACKS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration_sec;
} Track;

extern Track playlist[MAX_TRACKS];
extern int current_track;
extern int total_tracks;

void init_playlist();
void next_track();
void prev_track();
void print_playlist();

#endif
