/*
 *    $$$$$$$$\ $$\                                   
 *    \__$$  __|\__|                                  
 *       $$ |   $$\ $$$$$$\$$$$\   $$$$$$\   $$$$$$\  
 *       $$ |   $$ |$$  _$$  _$$\ $$  __$$\ $$  __$$\ 
 *       $$ |   $$ |$$ / $$ / $$ |$$$$$$$$ |$$ |  \__|
 *       $$ |   $$ |$$ | $$ | $$ |$$   ____|$$ |      
 *       $$ |   $$ |$$ | $$ | $$ |\$$$$$$$\ $$ |      
 *       \__|   \__|\__| \__| \__| \_______|\__|      
		----------------------------------------                       
Using timer 1, provides a 10 minute timer.              
 */

 #include "Timer.h"
 //Variables
 volatile int ctr_ = 0;
 volatile int timerStatus_ = 0;

 int returnerTimerStatus()
 {
	if (timerStatus_ == '0')
	{
		return 0;
	}
	else
	{
		return 1;
	}
 }



 void resetTimer()
 {
	timerStatus_ = '0';
	ctr_ = 0;
 }


 void setTimer()
 {
      //Sæt timerStatus til '1' (=going)
      timerStatus_ = '1';
	  // Timer1: Normal mode, PS = 1024
	  TCCR1A = 0b00000000;
	  TCCR1B = 0b00000101;
	  // Enable Timer1 overflow interrupt
	  TCNT1 = (0xFFFF-15625);
	  TIMSK1 |= 0b00000001;
	  
}

 ISR(TIMER1_OVF_vect)
 {
	 // Tæller ctr_ op hvert sekund.
	 ctr_++;
	 //	sætter tcnt1 til krævet værdi for 1s delay
	 TCNT1 = (0xFFFF-15625);

	 if (ctr_ == 600) //overflow 1 gang i sekundet betyder 600 = 10 min.	 
	 {
		resetTimer();
		TIMSK1 &= 0;
	 }
 }