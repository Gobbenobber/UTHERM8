#include "avr/interrupt.h"
#include "avr/io.h"
#include "RegistrerLektor_Optaget.h"
#include "Timer.h"

 // Global interrupt enable
 

  void initTimer0()
  {

  }

void resetTimer()
{
	//int tReset_ = 1;
}




 void setTimer()
 {

 // Timer0: Normal mode, PS = 1024 
 TCCR1A = 0b00000000;
 TCCR1B = 0b00000101;
 // Enable Timer0 overflow interrupt
 TIMSK1 |= 0b00000001;
 TCNT1 = (0xFFFF);

 sei();

 ISR(TIMER1_OVF_vect)
  {
	  // Tæller ctr_ op hvert sekund.
	  ctr_++;
	  if (ctr_ == 1800) //overflow 1 gang i sekundet
	  {
		  ctr_ = 0;
		  //TCNT1 = (0xFFFF-15625);
	  }
  }
 
	 //while (ctr_ < 1800)
	 //{
		//if (tReset_ == 1)
		//{
		//ctr_ = 0;
		//tReset_ = 0;
		//}
		 //
		 //
		 ////1 s pr. overflow.
		 //TCNT1 = (0xFFFF-15625);
		 //
		 ////Prescaler = 1024, normal mode.
		 //TCCR1A = 0x00000000;
		 //TCCR1B = 0x00000101;
		 //
		 //while ((TIFR1 & (1<<0)) == 0) {}
//
		 //TCCR1B = 0;
//
		 //TIFR1 = 1<<0;
	 //}
 }
 