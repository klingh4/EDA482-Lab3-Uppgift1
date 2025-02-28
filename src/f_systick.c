#include "h_systick.h"

void delay_250ns() {
	*STK_CTRL = 0;
	*STK_LOAD = 42;
	*STK_VAL = 0;
	*STK_CTRL = 0x5;
	while((*STK_CTRL & 0x10000) == 0);
	*STK_CTRL = 0;
}

void delay_micro(unsigned int us) {
	for(unsigned int i=0; i<us; i++) {
		delay_250ns();
		delay_250ns();
		delay_250ns();
		delay_250ns();
	}
}

void delay_milli(unsigned int ms) {
	for(unsigned int i=0; i < ms; i++) {
		delay_micro(1000); 
	}
}