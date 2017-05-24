/*

 */ 

 #include "Timer_3.h"

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
 
      //Sæt timerStatus til '1' (=going)
	  timerStatus_ = '1';	
	  // Timer3: Normal mode, PS = 1024
	  TCCR3A = 0b00000000;
	  TCCR3B = 0b00000101;
	  // Enable Timer3 overflow interrupt
	  TCNT3 = (0xFFFF-15625);
	  TIMSK3 |= 0b00000001;
	  
}

 ISR(TIMER3_OVF_vect)
 {
	 // Tæller ctr_ op hvert sekund.
	 ctr_++;
	 //	sætter tcnt3 til krævet værdi for 1s delay
	 TCNT3 = (0xFFFF-15625);

	 if (ctr_ == 600) //overflow 1 gang i sekundet betyder 600 = 10 min.	 
	 {
		timerStatus_ = '0';
		ctr_ = 0;
		TIMSK3 &= 0;
	 }
 }