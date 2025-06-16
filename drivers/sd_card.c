#include <stddef.h> // Fix NULL
#include "sd_card.h"

int sd_card_init(void) {
    return 0;  // Implementación temporal exitosa
}

int sd_read(uint8_t* buffer, uint32_t sector) {
    // Implementación temporal
    return 0;
}

int sd_get_filesize(const char* filename) {
    // Implementación temporal
    return 1024 * 1024; // 1 MB dummy
}
