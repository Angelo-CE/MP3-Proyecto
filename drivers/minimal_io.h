#include <stddef.h> // Fix NULL
#ifndef MINIMAL_IO_H
#define MINIMAL_IO_H

void debug_putchar(char c);
void debug_puts(const char *str);
void debug_putint(int num);

#endif
