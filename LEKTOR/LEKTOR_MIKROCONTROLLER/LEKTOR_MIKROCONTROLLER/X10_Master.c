/*
 * CFile1.c
 *
 * Created: 26-05-2017 01:04:53
 *  Author: Batuik
 */ 


 #include "X10_Master.h"
 #include "RegistrerLektor_Optaget.h"
 #include "RegistrerLektor_PaaKontor.h"
 #include "Timer.h"
 #include "zeroCrossDetector.h"

 volatile static int state;
 volatile static int firstCheck = 1;
 volatile static int lektorGone_;

 void opdaterKommando()
 {
	 if ((lektorOptaget_ == '0') && (lektortilStede_ == '0'))
	 {
		 if ((state == 00) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 aendring_ = 1;
			 COMMAND = 'A'; // V indikerer at lektor er v�k!	
			 state = 00;
			 lektorGone_ = 0;   
		 }
	 }
	 else if ((lektorOptaget_ == '0') && (lektortilStede_ == '1'))
	 {
		 if ((state == 01) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 resetTimer();
			 aendring_ = 1;
			 COMMAND = 'F';		// T Indikerer at lektor er tilstede
			 state = 01;
			 lektorGone_ = 0;
		 }
	 }
	 else if ((lektorOptaget_ == '1') && (lektortilStede_ == '0'))
	 {
		 if ((state == 10) && (firstCheck != 1))
		 {
			 aendring_ = 0;
			 if (returnerTimerStatus() == 0 && lektorGone_ != 1)
			 {
			 aendring_ = 1;
			 COMMAND = 'A';		//A FOR AWAY
			 state = 10;
			 lektorGone_ = 1;
			 }
		 }
		 else
		 {		
			 setTimer();
			 aendring_ = 1;
			 COMMAND = 'B';		// O indikerer at lektor har benyttet ToggleSwitch (=Optaget)
			 state = 10;
			 lektorGone_ = 0;
		 }
	 }
	 else if ((lektorOptaget_ == '1') && (lektortilStede_ == '1'))
	 {
		 if ((state == 11) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 aendring_ = 1;
			 COMMAND = 'B';		// O indikerer at lektor har benyttet ToggleSwitch (=Optaget)
			 state = 11;
			 lektorGone_ = 0;
		 }
	 }

	 if (firstCheck == 1)
	 {
		 firstCheck = 0;
	 }

 }

  void start1msDelay()
  {
	  // Timer3: Normal mode, PS = 0
	  TCCR3A = 0b00000000;
	  TCCR3B = 0b00000001;
	  // Overflow hvert MS.
	  //S�t timerStatus til '1' (=going)
	  //timerStatus_3 = '1';
	  TCNT3 = (0xFFFF-16000);
	  while ((TIFR3 & (1<<0)) == 0)
	  {}
	  TCCR3B = 0;
	  TIFR3 = 1<<0;
	  //timerStatus_3 = '0';
  }

  void sendBurst()
  {
	  ZCDetected_ = 0;
	  //PORTB = OUTPUT -- lad 120kHz signal fra OCRB komme ud.
	  DDRB |= 1 << 7;
	  start1msDelay();
	  //S�t PORTH til input igen.
	  DDRB &= ~(1 << 7);
  }

  void ventPaaZC()
  {
	  ZCDetected_ = 0;
	  while(ZCDetected_ == 0)	{}
  }

  void initBurst()
  {
	  // PB7/OC0A = input (burst not outgoing)
	  DDRB = (1 << 7);
	  // Toggle OC0A on compare match
	  // Mode = 4 (CTC); Clock prescaler = 1
	  TCCR0A = 0b01000010;
	  TCCR0B = 0b00000001;
	  // 120kHz = 16000000Hz/(2*1*(1+OCR1B))  --> OC0A = 119kHz...
	  OCR0A = 66;
  }

  void sendCharX10(char Tegn)
  {
	  // Main-loop: Toggle LED7 hvert sekund
	  unsigned char i;
	  unsigned char x = Tegn;
	  // Start bit
	  //ventPaaZC();
	  //sendBurst();
	  // 8 data bits (LSB first)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	  for (i = 0; i<8; i++)
	  {
	  ventPaaZC();
	  start1msDelay();
	  start1msDelay();
	  start100usDelay();
		  if(x & 0b10000000)
		  {
			  sendBurst();
		  }
		  x = x<<1;
	  }
	  //ventPaaZC();
	  //sendBurst(); //stopbit
	  //Test ###DUNNO what the stopbit is###
  }

   void start100usDelay()
   {
	   // Timer4: Normal mode, PS = 0
	   TCCR4A = 0b00000000;
	   TCCR4B = 0b00000001;
	   // Overflow hvert MS.
	   //S�t timerStatus til '1' (=going)
	   //timerStatus_3 = '1';
	   TCNT4 = 63936;
	   while ((TIFR4 & (1<<0)) == 0)
	   {}
	   TCCR4B = 0;
	   TIFR4 = 1<<0;
	   //timerStatus_3 = '0';
   }