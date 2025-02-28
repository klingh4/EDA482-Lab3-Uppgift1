#ifndef H_HEADER_H
#define H_HEADER_H

// Den här siffran skall sättas lämpligt för att ni skall kunna se den blinkande
// lampan i simulatorn.
#define PERIOD 100

#define GPIO_E_BASE 0x40021000
#define GPIO_E_MODER ((volatile unsigned int *) (GPIO_E_BASE + 0x0))
#define GPIO_E_OTYPER ((volatile unsigned int *) (GPIO_E_BASE + 0x4))
#define GPIO_E_PUPDR ((volatile unsigned int *) (GPIO_E_BASE + 0xC))
#define GPIO_E_IDR ((volatile unsigned int *) (GPIO_E_BASE + 0x10))
#define GPIO_E_ODR ((volatile unsigned int *) (GPIO_E_BASE + 0x14))


#endif