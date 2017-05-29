/*

 */ 

 #include "Timer_3_Interrupt.h"

 //int returnerTimer3Status()
 //{
	//return timerStatus_3;
 //}
//
//
//
 //void resetTimer3()
 //{
 	//timerStatus_3 = '0';
	//ctr_3 = 0;
 //}




 void T3Delay_1ms()
 {
 
      // Timer3: Normal mode, PS = 0
	  TCCR3A = 0b00000000;
	  TCCR3B = 0b00000001;
	  // Enable Timer3 overflow interrupt
	  // Overflow hvert MS.
	  //Sæt timerStatus til '1' (=going)
	  timerStatus_3 = '1';
	  TCNT3 = (0xFFFF-16000);
	  while ((TIFR3 & (1<<0)) == 0) {}
	  {
	  }
	  TCCR3B = 0;
	  TIFR3 = 1<<0;
	  timerStatus_3 = '0';
}

 //ISR(TIMER3_OVF_vect)
 //{
	 //// Tæller ctr_ op hvert sekund.
	 //ctr_3++;
	 ////	sætter tcnt3 til krævet værdi for 1s delay
	 //TCNT3 = (0xFFFF-15625);
 //}