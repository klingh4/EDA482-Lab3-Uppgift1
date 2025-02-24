#include "h_systick.h"
#include "h_interrupt.h"


// Den här siffran skall sättas lämpligt för att ni skall kunna se den blinkande
// lampan i simulatorn.
#define PERIOD 100

void main()
{
  InitSquareWave();
  StartSquareWave(PERIOD); 
  while(1) { /* Gör ingenting */ }
  StopSquareWave(); 
}


