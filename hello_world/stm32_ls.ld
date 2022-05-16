
MEMORY{
    FLASH(rx): ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 80K
}

ENTRY(Reset_Handler)

SECTIONS{

    /* The 'text' section contains the main program code. */
    .text :
    {
        *(.vector_table)
        *(.text)
            *(.rodata)
            . = ALIGN(4);
            _etext = .;
    } >FLASH

     _la_data = LOADADDR(.data);

    .data :
    {
        _sdata = .;
            *(.data)
            . = ALIGN(4);
            _edata = .;
    }> SRAM AT > FLASH

    /* The 'bss' section is similar to the 'data' section,
    * but its space is initialized to all 0s at the
    * start of the program. */
    .bss :
    {
        . = ALIGN(4);
        /* Also mark the start/end of the BSS section. */
        _sbss = .;
            *(.bss)
            . = ALIGN(4);
            _ebss = .;
            . = ALIGN(4);
    } >SRAM
}