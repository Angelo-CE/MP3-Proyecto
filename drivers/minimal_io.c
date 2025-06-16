#include "minimal_io.h"

// Direcciones base para UART en DE-SoC (ajustar según tu diseño)
#define UART_BASE 0xFFC02000
#define UART_DATA_REG   (*(volatile unsigned int *)(UART_BASE + 0x00))
#define UART_STATUS_REG (*(volatile unsigned int *)(UART_BASE + 0x04))

void debug_puts(const char *str) {
    while (*str) {
        // Esperar hasta que UART esté listo
        while (UART_STATUS_REG & 0x100); 
        UART_DATA_REG = *str++;
    }
}

void debug_putint(int num) {
    char buffer[12];
    char *p = buffer + 11;
    *p = '\0';
    
    int is_negative = 0;
    if (num < 0) {
        is_negative = 1;
        num = -num;
    } else if (num == 0) {
        *--p = '0';
    }
    
    while (num != 0) {
        *--p = '0' + (num % 10);
        num /= 10;
    }
    
    if (is_negative) {
        *--p = '-';
    }
    
    debug_puts(p);
}
