#ifndef _GRAPHLIB
#define _GRAPHLIB
#include <libndls.h>
#include "charmap.h"

uint16_t pxBuf[320*240];
scr_type_t pxBuf_type;

// Gets LCD type and initializes the LCD
void initGL() {
    pxBuf_type = lcd_type();
    lcd_init(pxBuf_type);
}

// Set pixel
void setPixel(int x, int y, uint16_t c) {
	if(pxBuf_type == SCR_240x320_565)	// HW-W
		pxBuf[y+x*240] = c;
	else if(pxBuf_type == SCR_320x240_565)	// not tested!
		pxBuf[x+y*240] = c;
	else if(pxBuf_type == SCR_320x240_8)	// not tested!
		pxBuf[x/2+y*120] = (c >> 8 * x%2)%256;
	else if(pxBuf_type == SCR_320x240_4)	// not tested
		pxBuf[x/4+y*60] = (c >> 4 * x%4)%16;
}

// Draws rect
void drawRect(int x1, int y1, int x2, int y2, uint16_t color) {
    for(int x = x1; x < x2; x++) {
        for(int y = y1; y < y2; y++) {
            setPixel(x, y, color);
        }
    }
}

// Updates LCD (Using lcd_blit())
void updateLCD() {
    lcd_blit(pxBuf, pxBuf_type);
}

// Puts char on screen
void lcd_putc(int x, int y, int c, unsigned char character) {
	for(int i = 0; i < 12; i++) {
		for(int b = 0; b < 8; b++) {
			if((charMap_ascii[character][i]>>b)%2) {
				setPixel(y+7-b,x+i,c);
			}
		}
	}
}

// Puts char* on screen
void lcd_puts(int x, int y, int c, char* str) {
	for(uint8_t i = 0; i < strlen(str); i++) {
		lcd_putc(y,x+9*i,c,str[i]);
	}
}

// Puts char* on screen, seperate background color
void lcd_putsSelected(int x, int y, int fg, int bg, char* str) {
    drawRect(x-4, y-4, x+strlen(str)*9+4, y+16, bg);
	for(uint8_t i = 0; i < strlen(str); i++) {
		lcd_putc(y,x+9*i,fg,str[i]);
	}
}
#endif
