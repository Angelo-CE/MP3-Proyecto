#include "ui.h"
#include "minimal_io.h"
#include "state_machine.h"
#include "playlist.h"

// Definición única aquí
const char* status_icons[] = {
    "[STOP]",  // STOPPED
    "[PLAY]",  // PLAYING
    "[PAUSE]", // PAUSED
    "[IDLE]"   // IDLE
};

void show_playback_status(int frame) {
    char buffer[60];
    int pos = 0;
    
    // Construir mensaje manualmente
    const char* icon = status_icons[current_state];
    while (*icon) buffer[pos++] = *icon++;
    buffer[pos++] = ' ';
    
    const char* name = playlist[current_track].name;
    while (*name) buffer[pos++] = *name++;
    
    // Formato MM:SS
    buffer[pos++] = ' ';
    buffer[pos++] = '0' + (frame/60)/10;
    buffer[pos++] = '0' + (frame/60)%10;
    buffer[pos++] = ':';
    buffer[pos++] = '0' + (frame%60)/10;
    buffer[pos++] = '0' + (frame%60)%10;
    buffer[pos++] = '/';
    
    int total_min = playlist[current_track].duration_sec/60;
    int total_sec = playlist[current_track].duration_sec%60;
    buffer[pos++] = '0' + total_min/10;
    buffer[pos++] = '0' + total_min%10;
    buffer[pos++] = ':';
    buffer[pos++] = '0' + total_sec/10;
    buffer[pos++] = '0' + total_sec%10;
    
    buffer[pos] = '\0';
    
    // Enviar por UART
    debug_puts(buffer);
    debug_puts("\n");
}
