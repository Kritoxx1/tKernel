; boot.s - NASM syntax
[BITS 32]
[GLOBAL start]

; --- Multiboot header ---
; --- Code ---
section .text
global start
extern kmain
start:
    cli
    mov esp, stack_top
    call kmain

multiboot_header: 
    align 4
    dd 0x1BADB002        ; magic
    dd 0x00000003         ; flags: align | memory info
    dd -(0x1BADB002 + 0x3) ; checksum

;
hang:
    hlt
    jmp hang

; --- Stack ---
section .bss
align 16
stack_bottom:
    resb 16384          ; 16 KiB stack
stack_top:

