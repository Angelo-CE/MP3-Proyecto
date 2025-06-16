ENTRY(_start)

MEMORY {
    RAM (rwx) : ORIGIN = 0x00000000, LENGTH = 64M
}

SECTIONS {
    .text : {
        *(.vectors)
        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
        _etext = .;
    } > RAM

    .data : AT ( _etext ) {
        _data_start = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _data_end = .;
    } > RAM
    _data_load_start = LOADADDR(.data);

    .bss : {
        _bss_start = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _bss_end = .;
    } > RAM

    .heap : {
        . = ALIGN(4);
        _heap_start = .;
        . = . + 0x4000; /* 16KB heap */
        _heap_end = .;
    } > RAM

    _end = .;   /* Para _sbrk */
    _stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
