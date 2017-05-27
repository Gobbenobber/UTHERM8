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

 volatile int state;
 int firstCheck = 1;


 void opdaterKommando()
 {
	 if (lektorOptaget_ == '0' && lektortilStede_ == '0')
	 {
		 if ((state = 00) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 aendring_ = 1;
			 COMMAND = 'V';		// V indikerer at lektor er v�k!
		 }
		 state = 00;
	 }
	 else if ((lektorOptaget_ == '0') && (lektortilStede_ == '1'))
	 {
		 if ((state = 01) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 aendring_ = 1;
			 COMMAND = 'T';		// T Indikerer at lektor er tilstede
			 state = 01;
		 }
	 }
	 else if ((lektorOptaget_ == '1') && (lektortilStede_ == '0'))
	 {
		 if ((state = 10) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 aendring_ = 1;
			 COMMAND = 'O';		// O indikerer at lektor har benyttet ToggleSwitch (=Optaget)
			 state = 10;
		 }
	 }
	 else if ((lektorOptaget_ == '1') && (lektortilStede_ == '1'))
	 {
		 if ((state = 11) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 if (returnerTimerStatus() == 0)
			 {
				 setTimer();
			 }
			 aendring_ = 1;
			 COMMAND = 'O';		// O indikerer at lektor har benyttet ToggleSwitch (=Optaget)
			 state = 11;
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
	  //s�t ZDDetected til 0 hvis der er ZeroCross.
	  if (ZCDetected_ == 1)
	  {
		  ZCDetected_ = 0;
	  }
	  //PORTB = OUTPUT -- lad 120kHz signal fra OCRB komme ud.
	  DDRH = 0xFF;
	  start1msDelay();
	  //S�t PORTH til input igen.
	  DDRH = 0;
  }

  void ventPaaZC()
  {
	  if (ZCDetected_ == 1)
	  {
		  ZCDetected_ = 0;
	  }
	  while(ZCDetected_ == 0)	{}
  }

  void initBurst()
  {
	  // PH = input (burst not outgoing)
	  DDRH = 0;
	  // Toggle OC2B on compare match
	  // Mode = 4 (CTC)
	  // Clock prescaler = 1
	  TCCR2A = 0b00010000;
	  TCCR2B = 0b00000001;
	  // Frekvens = 120.3 kHz
	  // 120kHz = 16000000Hz/(2*1*(1+OCR1A))  --> OCR1A = 131.33...
	  OCR2B = 131;
  }

  void sendCharX10(char Tegn)
  {
	  // Main-loop: Toggle LED7 hvert sekund
	  unsigned char i;
	  unsigned char x = Tegn;
	  // Start bit
	  ventPaaZC();
	  sendBurst();
	  // 8 data bits (LSB first)
	  for (i = 0; i<8; i++)
	  {
		  if(x & 0b00000001)
		  {
			  ventPaaZC();
			  sendBurst();
		  }
		  else
		  {
			  ventPaaZC();
			  start1msDelay();
		  }
		  x = x>>1;
	  }
	  ventPaaZC();
	  sendBurst(); //stopbit
	  //Test ###DUNNO what the stopbit is###
	  //PORT &= ~(1<<PINNR);
  }
