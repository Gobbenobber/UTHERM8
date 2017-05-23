/*
 * Timer.c
 *
 * Created: 22-05-2017 10:50:20
 *  Author: Kasper
 */ 

 #include "Timer.h"

 int returnerTimerStatus()
 {
	return timerStatus_;
 }



 void resetTimer()
 {
	ctr_ = 0;
	timerStatus_ = '0';
 }




 void setTimer()
 {
	  // Timer0: Normal mode, PS = 1024
	  TCCR1A = 0b00000000;
	  TCCR1B = 0b00000101;
	  // Enable Timer0 overflow interrupt
	  TCNT1 = (0xFFFF-15625);
	  TIMSK1 |= 0b00000001;
}

 ISR(TIMER1_OVF_vect)
 {
	 // Tæller ctr_ op hvert sekund.
	 ctr_++;
	 //sætter tcnt1 til krævet værdi for 1s delay
	 TCNT1 = (0xFFFF-15625);

	 if (ctr_ == 5) //overflow 1 gang i sekundet
	 {
		timerStatus_ = '1';
		ctr_ = 0;
		TIMSK1 &= 0;
	 }
 }