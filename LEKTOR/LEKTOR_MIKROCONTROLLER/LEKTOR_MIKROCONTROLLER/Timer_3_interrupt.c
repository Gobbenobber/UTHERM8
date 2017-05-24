/*

 */ 

 #include "Timer_3_Interrupt.h"

 int returnerTimer3Status()
 {
	return timerStatus_3;
 }



 void resetTimer3()
 {
 	timerStatus_3 = '0';
	ctr_3 = 0;
 }




 void setTimer3()
 {
 
      //S�t timerStatus til '1' (=going)
	  timerStatus_3 = '1';	
	  // Timer3: Normal mode, PS = 1024
	  TCCR3A = 0b00000000;
	  TCCR3B = 0b00000101;
	  // Enable Timer3 overflow interrupt
	  TCNT3 = (0xFFFF-15625);
	  TIMSK3 |= 0b00000001;
	  
}

 ISR(TIMER3_OVF_vect)
 {
	 // T�ller ctr_ op hvert sekund.
	 ctr_3++;
	 //	s�tter tcnt3 til kr�vet v�rdi for 1s delay
	 TCNT3 = (0xFFFF-15625);
 }