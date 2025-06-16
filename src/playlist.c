#include "playlist.h"
#include "minimal_io.h"
#include <stddef.h>

// strncpy personalizada
void my_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n - 1 && src[i]; i++) dest[i] = src[i];
    dest[i] = '\0';
}

Track playlist[MAX_TRACKS];
int   current_track = 0;
int   total_tracks  = 0;

void init_playlist(void) {
    total_tracks = 2;

    my_strncpy(playlist[0].name,   "Cancion1", sizeof playlist[0].name);
    my_strncpy(playlist[0].artist, "Artista1", sizeof playlist[0].artist);
    my_strncpy(playlist[0].album,  "Album1",   sizeof playlist[0].album);
    playlist[0].duration = 180;

    my_strncpy(playlist[1].name,   "Cancion2", sizeof playlist[1].name);
    my_strncpy(playlist[1].artist, "Artista2", sizeof playlist[1].artist);
    my_strncpy(playlist[1].album,  "Album2",   sizeof playlist[1].album);
    playlist[1].duration = 240;

    debug_puts("Playlist inicializada con ");
    debug_putint(total_tracks);
    debug_puts(" canciones\n");
}

void next_track(void) {
    if (total_tracks) current_track = (current_track + 1) % total_tracks;
}

void prev_track(void) {
    if (total_tracks) current_track = (current_track - 1 + total_tracks) % total_tracks;
}

// Devuelve puntero para no necesitar memcpy
Track* get_current_track(void) {
    return &playlist[current_track];
}

