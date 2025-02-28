#include "h_interrupt.h"
#include "h_header.h"

void InitSquareWave() {
    *GPIO_E_MODER |= 0x1; //moder 0x1 = output
    *GPIO_E_OTYPER &= ~0x1; //otyper 0x0 = push-pull
    *GPIO_E_PUPDR &= ~0x3; //pupdr 0x0 = no pull-up/pull-down
    GPIO_E_ODR &= ~(0x1); //odr 0x0 = low
}

void StartSquarewave(unsigned int period_in_us) {
    
}

void StopSquareWave() {

}