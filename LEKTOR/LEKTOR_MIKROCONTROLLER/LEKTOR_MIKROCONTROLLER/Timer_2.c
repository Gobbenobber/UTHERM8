/*
 *    $$$$$$$$\$$\                                       $$$$$$\              $$\         $$\
 *    \__$$  __\__|                                     $$  __$$\             $$ |        $$ |
 *       $$ |  $$\$$$$$$\$$$$\  $$$$$$\  $$$$$$\        \__/  $$ |       $$$$$$$ |$$$$$$\ $$ |$$$$$$\ $$\   $$\
 *       $$ |  $$ $$  _$$  _$$\$$  __$$\$$  __$$\        $$$$$$  |      $$  __$$ $$  __$$\$$ |\____$$\$$ |  $$ |
 *       $$ |  $$ $$ / $$ / $$ $$$$$$$$ $$ |  \__|      $$  ____/       $$ /  $$ $$$$$$$$ $$ |$$$$$$$ $$ |  $$ |
 *       $$ |  $$ $$ | $$ | $$ $$   ____$$ |            $$ |            $$ |  $$ $$   ____$$ $$  __$$ $$ |  $$ |
 *       $$ |  $$ $$ | $$ | $$ \$$$$$$$\$$ |            $$$$$$$$\       \$$$$$$$ \$$$$$$$\$$ \$$$$$$$ \$$$$$$$ |.c
 *       \__|  \__\__| \__| \__|\_______\__|            \________|       \_______|\_______\__|\_______|\____$$ |
 *                                                                                                    $$\   $$ |
 *                                                                                                    \$$$$$$  |
 *                                                                                                     \______/
  */ 

 #include "Timer_2.h"
 #include <avr/io.h>

 void T2Delay_us(int delay_us) // MAX 15 uS DELAY!!!
 {
	 int us;
	 
	 if (delay_us <= 15 && delay_us > 0) //int delay_ms, skal v�re mellem 0 og 15
	 {
		 us = delay_us;
	 }
	 
	 else
	 
	 {
		 us = 1;
	 }
	 //x for 1s = 240 v. frav�r af PS, derfor 16*us
	 TCNT2 = (256-(16*us));
	 
	 //Prescaler = 0, normal mode.
	 TCCR2A = 0x00000000;
	 TCCR2B = 0x00000001;

	 //lav ingenting indtil timer 2 flag register s�ttes
	 while ((TIFR2 & (1<<0)) == 0) {}

	 TCCR2B = 0;

	 TIFR2 = 1<<0;
 }

