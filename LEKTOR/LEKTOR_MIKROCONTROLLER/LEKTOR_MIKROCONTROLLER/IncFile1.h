/*
				Timer2.c
----------------------------------
Driver til timer 1 delay op til max. 262 ms.

Bruges til at lave 20 ms. delay uden brug af _delay_ms() funktionen. 
----------------------------------

Created: 13-12-2016 10:52:59
Author: Batuik

 */ 


#include "timer2.h"
#include <avr/io.h>



void T2Delay(int delay_ms) // MAX 262 MS DELAY!!!
{
	int ms;
	
	if (delay_ms <= 262 && delay_ms > 0) //int delay_ms, skal være mellem 0 og 262
	{
		
		ms = delay_ms;
	}
	
	else
	
	{
		ms = 10;
	}
	
	TCNT1 = (0xFFFF-(ms*250));
	
	//Prescaler = 64, normal mode.
	TCCR1A = 0x00000000;
	TCCR1B = 0x00000011;
	
while ((TIFR1 & (1<<0)) == 0) {}

TCCR1B = 0;

TIFR1 = 1<<0;

}