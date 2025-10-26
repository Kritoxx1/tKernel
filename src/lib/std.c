/*
 * @author  ... Turan (Kritoxx1)
 * @date    ... created on 26.10.2025 / 
 *              Last update 26.10.2025
 * 
 **/

#include "std.h"
volatile uint16_t* vga = (uint16_t*)VGA_ADDR;

void kputs(const char* s) {

  while (*s) {
    *vga++ = (uint16_t)((0x07 << 8) | (unsigned char)*s);
    s++;
  }
}

void kputc(char c) {
  *vga++ = (0x07 << 8) | c;
}

void kprintf(const char *format, ...) {
  va_list args;

  char numbuf[32];
  va_start(args, format);

  for (char* i = format; *i != '\0'; i++) {
    if (*i == '%') {
      switch(*i++) {
        case 'd':
          int d = va_arg(args, int);
          itoa(d, numbuf, 10);
          kputs(numbuf);
          break;
        case 'x':
          int x = va_arg(args, int);
          itoa(x, numbuf, 16);
          kputs(numbuf);
          break;
        case 's':
          kputs(i);
          break;
      }
    } else {
      kputc(*i);
    } 
  }

  va_end(args);
}

// Utils

void itoa(int val, char* buf, int base) {
  char temp[32];
  int i = 0;
  Bool is_negative = false;

  if (val == 0) {
    buf[0] = '0';
    buf[1] = '\0';
    return;
  }

  if (val < 0 && base == 10) {
    is_negative = true;
    val = -val;
  }

  while (val != 0) {
    int digit = val % base;
    temp[i++] = (digit > 9) ? ('A' + digit - 10) : ('0' + digit);
    val /= base;
  }

  if (is_negative) temp[i++] = '-';

  int j;
  for(j = 0; j < i; j++) buf[j] = temp[i - j - 1];
  buf[i] = '\0';
}


// Ignore For now...
// ------------------------------
// ------------ VGA -------------
// ------------------------------
uint16_t detectBiosAreaHardware(void) { 
  const uint16_t* bda_detect_hardware_ptr = (const uint16_t*) 0x410; 
  return *bda_detect_hardware_ptr;
} 

enum video_type getBiosAreaVideoType(void) { 
  return (enum video_type) (detectBiosAreaHardware() & 0x30);
}


