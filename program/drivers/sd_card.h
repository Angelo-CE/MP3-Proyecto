#ifndef SD_CARD_H
#define SD_CARD_H

#include <stdint.h>

int sd_card_init(void);
int sd_read(uint8_t* buffer, uint32_t sector);
int sd_get_filesize(const char* filename);

#endif
