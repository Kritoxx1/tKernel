ENTRY(start)

SECTIONS
{
  . = 0x00100000;

  .text ALIGN(0x1000) : { 
    *(.multiboot)
    *(.text*)
  }

  .rodata ALIGN(4) : { *(.rodata*) }

  .data ALIGN(4) : { *(.data*) }

  .bss ALIGN(4) : { *(.bss*) ; *(COMMON) }
}
