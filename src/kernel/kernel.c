/*
 * @author  ... Turan (Kritoxx1)
 * @date    ... created on 26.10.2025 / 
 *              Last update 26.10.2025
 * 
 * */
#include "../lib/std.h"


void kmain(void) {
  kprintf("Hello from kprintf"); 

  // Halt the cpu.
  for (;;) __asm__ volatile("hlt");
}

// TODO
// detect keyboard input
// add commands
