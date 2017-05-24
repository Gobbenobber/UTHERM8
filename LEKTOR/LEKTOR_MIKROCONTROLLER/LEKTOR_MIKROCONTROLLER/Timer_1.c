/*
//  $$$$$$$$\ $$\                                           $$\         $$$$$$\ $$\   $$\ $$$$$$$$\
//  \__$$  __|\__|                                        $$$$ |        \_$$  _|$$$\  $$ |\__$$  __|
//     $$ |   $$\ $$$$$$\$$$$\   $$$$$$\   $$$$$$\        \_$$ |          $$ |  $$$$\ $$ |   $$ |
//     $$ |   $$ |$$  _$$  _$$\ $$  __$$\ $$  __$$\         $$ |          $$ |  $$ $$\$$ |   $$ |
//     $$ |   $$ |$$ / $$ / $$ |$$$$$$$$ |$$ |  \__|        $$ |          $$ |  $$ \$$$$ |   $$ |
//     $$ |   $$ |$$ | $$ | $$ |$$   ____|$$ |              $$ |          $$ |  $$ |\$$$ |   $$ |
//     $$ |   $$ |$$ | $$ | $$ |\$$$$$$$\ $$ |            $$$$$$\       $$$$$$\ $$ | \$$ |   $$ |
//     \__|   \__|\__| \__| \__| \_______|\__|            \______|      \______|\__|  \__|   \__|.c

 */ 

 #include "Timer_1.h"

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
		timerStatus_ = '0';
		ctr_ = 0;
		TIMSK1 &= 0;
	 }
 }