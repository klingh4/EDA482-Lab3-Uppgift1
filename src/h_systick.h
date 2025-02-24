#ifndef H_SYSTICK_H
#define H_SYSTICK_H

#define STK_BASE 0xE000E010
#define STK_CTRL ((volatile unsigned int *)(STK_BASE + 0x00))  
#define STK_LOAD ((volatile unsigned int *)(STK_BASE + 0x04))
#define STK_VAL ((volatile unsigned int *)(STK_BASE + 0x08))

void delay_250ns();
void delay_milli(unsigned int ms);
void delay_micro(unsigned int us);


#endif // H_SYSTICK_H