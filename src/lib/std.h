/*
 * @author  ... Turan (Kritoxx1)
 * @date    ... created on 26.10.2025 / 
 *              Last update 26.10.2025
 * 
 * */

#ifndef STD_H
#define STD_H

#include <stdarg.h>

typedef unsigned int    uint32_t;
typedef unsigned short  uint16_t;
typedef unsigned char   uint8_t;
typedef void            vro; // Useless for now...

// Bool
typedef char Bool;
#define true 0xFF
#define false 0x00


enum video_type {
  VIDEO_TYPE_NONE = 0x00,
  VIDEO_TYPE_COLOR = 0x20,
  VIDEO_TYPE_MONOCHROME = 0x30,
};

uint16_t detectBiosAreaHardware(void);
enum video_type getBiosAreaVideoType(void);

#define VGA_ADDR 0xB8000U
extern volatile uint16_t* vga;

void kprintf(const char* format, ...);

/**
 * @brief         ... Printing text in red. Helpful for Debug
 * @param format  ... 
 * */
void kperror(const char* format, ...);

void kputs(const char* s);
void kputc(char c);

// Utils
void itoa(int val, char* buf, int base);


#endif // STD_H
