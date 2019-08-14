/* nPeek v1.0 */
#include <libndls.h>
#include "graphLib.h"

int indexHorizontal = 0;
int indexVertical = 0;
int indexHmax = 2;
int indexVmax = 0;
char dataBackup[3];
char data[3][8];
bool screenChanged = true;
bool performCmd = false;

uint32_t peek(uint32_t* addr) {
	return *addr;
}

uint32_t poke(uint32_t* addr, uint32_t data) {
	*addr = data;
	return *addr;
}

// Sets data between from_addr(included) and to_addr(included) to data
void fill(uint32_t* from_addr, uint32_t* to_addr, uint32_t data) {
	for(uint32_t* addr = from_addr; addr <= to_addr; addr++) {
		*addr = data;
	}
}

// Handle key presses, return true if ESC pressed.
bool handleKey() {
	if(isKeyPressed(KEY_NSPIRE_ESC)) {				// EXIT
		return true;
	} else if(isKeyPressed(KEY_NSPIRE_UP)) {		// Menu UP
		indexVertical--;
		if(indexVertical < 0)
			indexVertical = 0;
	} else if(isKeyPressed(KEY_NSPIRE_DOWN)) {		// Menu DOWN
		indexVertical++;
		if(indexVertical > indexVmax)
			indexVertical = indexVmax;
	} else if(isKeyPressed(KEY_NSPIRE_LEFT)) {		// Menu LEFT
		indexHorizontal--;
		if(indexHorizontal < 0)
			indexHorizontal = indexHmax;
		indexVertical = 0;
	} else if(isKeyPressed(KEY_NSPIRE_RIGHT)) {		// Menu RIGHT
		indexHorizontal++;
		if(indexHorizontal > indexHmax)
			indexHorizontal = 0;
		indexVertical = 0;
	} else if(isKeyPressed(KEY_NSPIRE_0)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '0';
	} else if(isKeyPressed(KEY_NSPIRE_1)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '1';
	} else if(isKeyPressed(KEY_NSPIRE_2)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '2';
	} else if(isKeyPressed(KEY_NSPIRE_3)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '3';
	} else if(isKeyPressed(KEY_NSPIRE_4)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '4';
	} else if(isKeyPressed(KEY_NSPIRE_5)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '5';
	} else if(isKeyPressed(KEY_NSPIRE_6)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '6';
	} else if(isKeyPressed(KEY_NSPIRE_7)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '7';
	} else if(isKeyPressed(KEY_NSPIRE_8)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '8';
	} else if(isKeyPressed(KEY_NSPIRE_9)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = '9';
	} else if(isKeyPressed(KEY_NSPIRE_A)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = 'A';
	} else if(isKeyPressed(KEY_NSPIRE_B)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = 'B';
	} else if(isKeyPressed(KEY_NSPIRE_C)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = 'C';
	} else if(isKeyPressed(KEY_NSPIRE_D)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = 'D';
	} else if(isKeyPressed(KEY_NSPIRE_E)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = 'E';
	} else if(isKeyPressed(KEY_NSPIRE_F)) {
		dataBackup[indexVertical] = data[indexVertical][0];
		for(int i = 0; i < 7; i++) {
			data[indexVertical][i] = data[indexVertical][i+1];
		}
		data[indexVertical][7] = 'F';
	} else if(isKeyPressed(KEY_NSPIRE_ENTER)) {
		performCmd = true;
	} else if(isKeyPressed(KEY_NSPIRE_DEL)) {
		for(int i = 6; i >= 0; i--) {
			data[indexVertical][i+1] = data[indexVertical][i];
		}
		data[indexVertical][0] = dataBackup[indexVertical];
		dataBackup[indexVertical] = '0';
	}
	return false;
}

// Routine to draw menus and data
void drawScreen() {
	// Clear screen
	drawRect(0, 0, 320, 240, 0x0000);

	// Draw menu
	lcd_puts(53, 20, 0xCE59, "PEEK");
	lcd_puts(141, 20, 0xCE59, "POKE");
	lcd_puts(229, 20, 0xCE59, "FILL");
	switch(indexHorizontal) {
		case 0:	// PEEK
			indexVmax = 0;
			lcd_putsSelected(53, 20, 0x0000, 0xCE59, "PEEK");
			lcd_putsSelected(10, 50, 0x0000, 0xCE59, "Address");
			lcd_puts(141, 50, 0xCE59, "0x");
			for(int i = 0; i < 8; i++) {
					lcd_putc(50, 160+i*9, 0xCE59, data[0][i]);
				}
			break;
		case 1:	// POKE
			indexVmax = 1;
			lcd_putsSelected(141, 20, 0x0000, 0xCE59, "POKE");
			lcd_puts(10, 50, 0xCE59, "Address"); lcd_puts(141, 50, 0xCE59, "0x");
			lcd_puts(10, 80, 0xCE59, "Value"); lcd_puts(141, 80, 0xCE59, "0x");
			for(int j = 0; j < 2; j++) {
				for(int i = 0; i < 8; i++) {
					lcd_putc(50+30*j, 160+i*9, 0xCE59, data[j][i]);
				}
			}
			switch(indexVertical) {
				case 0:
					lcd_putsSelected(10, 50, 0x0000, 0xCE59, "Address");
					break;
				case 1:
					lcd_putsSelected(10, 80, 0x0000, 0xCE59, "Value");
					break;
			}
			break;
		case 2:	// FILL
			indexVmax = 2;
			lcd_putsSelected(229, 20, 0x0000, 0xCE59, "FILL");
			lcd_puts(10, 50, 0xCE59, "From Address"); lcd_puts(141, 50, 0xCE59, "0x");
			lcd_puts(10, 80, 0xCE59, "To Address"); lcd_puts(141, 80, 0xCE59, "0x");
			lcd_puts(10, 110, 0xCE59, "Value"); lcd_puts(141, 110, 0xCE59, "0x");
			for(int j = 0; j < 3; j++) {
				for(int i = 0; i < 8; i++) {
					lcd_putc(50+30*j, 160+i*9, 0xCE59, data[j][i]);
				}
			}
			switch(indexVertical) {
				case 0:
					lcd_putsSelected(10, 50, 0x0000, 0xCE59, "From Address");
					break;
				case 1:
					lcd_putsSelected(10, 80, 0x0000, 0xCE59, "To Address");
					break;
				case 2:
					lcd_putsSelected(10, 110, 0x0000, 0xCE59, "Value");
					break;
			}
			break;
	}
	lcd_puts(10, 200, 0xCE59, "Return");
	lcd_puts(84, 200, 0xCE59, "<Press ENTER>");

	// Update LCD buffer
	updateLCD();
}

// Converts HEX string to uint32_t
uint32_t hexToInt(char hexNr[8]) {
	uint32_t intNr = 0;
	for(int i = 0; i < 8; i++) {
		if(hexNr[i] >= '0' && hexNr[i] <= '9') {
			intNr += (hexNr[i] - (uint32_t)'0') * pow(16,7-i);
		} else if(hexNr[i] >= 'a' && hexNr[i] <= 'f') {
			intNr += (hexNr[i] - (uint32_t)'a'+10) * pow(16, 7-i);
		} else if(hexNr[i] >= 'A' && hexNr[i] <= 'F') {
			intNr += (hexNr[i] - (uint32_t)'A'+10) * pow(16, 7-i);
		}
	}
	return intNr;
}

int main(void) {
	for(int i = 0; i < 24; i++) {
		data[i%3][i%8] = '0';
	}

	initGL();
	
	while(1) {
		// Key pressed?
		if(any_key_pressed()) {
			screenChanged = true;
			if(handleKey())
				break;
			for(int i = 0; i < 5000000; i++) {
				__asm__("nop");
			}
		}

		// Screen changed?
		if(screenChanged) {
			drawScreen();
			screenChanged = false;
		}

		// Enter pressed?
		if(performCmd) {
			char tmp[10];
			switch(indexHorizontal) {
				case 0:		// PEEK
					utoa(peek((uint32_t*)hexToInt(data[0])), tmp, 10);
					lcd_putsSelected(84, 200, 0x0000, 0xCE59, tmp);
					tmp[0] = '0'; tmp[1] = 'x';
					utoa(peek((uint32_t*)hexToInt(data[0])), ((char*)tmp+2), 16);
					lcd_putsSelected(200, 200, 0x0000, 0xCE59, tmp);
					break;
				case 1:		// POKE
					poke((uint32_t*)hexToInt(data[0]),hexToInt(data[1]));
					utoa(peek((uint32_t*)hexToInt(data[0])), tmp, 10);
					lcd_putsSelected(84, 200, 0x0000, 0xCE59, tmp);
					tmp[0] = '0'; tmp[1] = 'x';
					utoa(peek((uint32_t*)hexToInt(data[0])), ((char*)tmp+2), 16);
					lcd_putsSelected(200, 200, 0x0000, 0xCE59, tmp);
					break;
				case 2:		// FILL
					fill((uint32_t*)hexToInt(data[0]),(uint32_t*)hexToInt(data[1]),hexToInt(data[2]));
					utoa(hexToInt(data[2]), tmp, 10);
					lcd_putsSelected(84, 200, 0x0000, 0xABCD, tmp);
					break;
			}
			updateLCD();
			performCmd = false;
		}
	}
	return 0;
}
