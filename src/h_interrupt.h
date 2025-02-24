#ifndef H_INTERRUPT_H
#define H_INTERRUPT_H


// I den här funktionen skall lägre byten av Port E förberedas för att lägga
// ut en signal på pinne 0. Den skall bara kallas en gång. 
void InitSquareWave(); 

// När man kallat den här funktionen skall en fyrkantsvåg med given period 
// (i mikrosekunder) läggas ut på pinne 0, Port E. Perioden skall kunna 
// vara upp till 99000 mikrosekunder.
void StartSquarewave(unsigned int period_in_us);

// Den här funktionen skall avbryta fyrkantsvågen. 
void StopSquareWave(); 


#endif // H_INTERRUPT_H