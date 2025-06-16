#include <stddef.h> // Fix NULL
#include <errno.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>
#include <sys/types.h> // Para caddr_t
#include "minimal_io.h"

#undef errno
extern int errno;

void _exit(int status) {
    while(1);
}

int _close(int file) {
    return -1;
}

int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    return 0;
}

int _read(int file, char *ptr, int len) {
    return 0;
}

int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        debug_putchar(ptr[i]);
    }
    return len;
}

caddr_t _sbrk(int incr) {
    extern char _end;
    static char *heap_end = 0;
    char *prev_heap_end;

    if (heap_end == 0) {
        heap_end = &_end;
    }

    prev_heap_end = heap_end;
    heap_end += incr;

    return (caddr_t)prev_heap_end;
}
