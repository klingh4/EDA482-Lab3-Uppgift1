#include "h_systick.h"
#include "h_interrupt.h"
#include "h_header.h"


void main()
{
  InitSquareWave();
  StartSquareWave(PERIOD); 
  while(1) { /* Gör ingenting */ }
  StopSquareWave(); 
}

