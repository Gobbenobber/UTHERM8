/*
 * Timer_1.c
 *
 * Created: 24-05-2017 10:20:40
 *  Author: Batuik
 */ 

 #include "Timer_2.h"


 void T2Delay(int delay_us) // MAX 51 uS DELAY!!!
 {
	 int us;
	 
	 if (delay_us <= 262 && delay_us > 0) //int delay_ms, skal være mellem 0 og 262
	 {
		 
		 us = delay_us;
	 }
	 
	 else
	 
	 {
		 us = 8;
	 }
	 
	 TCNT2 = (255-(us*5));
	 
	 //Prescaler = 64, normal mode.
	 TCCR2A = 0x00000000;
	 TCCR2B = 0x00000011;
	 //lav ingenting indtil timer 2 flag register sættes
	 while ((TIFR2 & (1<<0)) == 0) {}

	 TCCR2B = 0;

	 TIFR2 = 1<<0;

 }