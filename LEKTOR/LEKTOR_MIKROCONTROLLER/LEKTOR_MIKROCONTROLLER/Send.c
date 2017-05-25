//Header
#include "Send.h"
#include "Timer_2.h"
#include "zeroCrossDetector.h"

// 8 data bit, no parity, 1 stop bit
void sendCharSW(char Tegn)
{
	// Main-loop: Toggle LED7 hvert sekund
	unsigned char i;
	unsigned char x = Tegn;
	// Start bit
	ventPaaZC();
	sendNothing();		//venter 8.3us
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
			sendNothing();
		}
		x = x>>1;
	}
	ventPaaZC();
	sendBurst(); //stopbit
	//Test ###DUNNO what the stopbit is###
	//PORT &= ~(1<<PINNR);
}

void sendBurst()
{
		 // Timer3: Normal mode, PS = 0
		 TCCR3A = 0b00000000;
		 TCCR3B = 0b00000001;
		 // Enable Timer3 overflow interrupt
		 // Overflow hvert MS.
		 //Sæt timerStatus til '1' (=going)
		 //timerStatus_3 = '1';
		 TCNT3 = (0xFFFF-16000);
		 while ((TIFR3 & (1<<0)) == 0) 
		 {
			PORT |= (1<<PINNR);
		 }
		 TCCR3B = 0;
		 TIFR3 = 1<<0;
		 //timerStatus_3 = '0';
	
}

void sendNothing()
{
		// Timer3: Normal mode, PS = 0
		TCCR3A = 0b00000000;
		TCCR3B = 0b00000001;
		// Enable Timer3 overflow interrupt
		// Overflow hvert MS.
		//Sæt timerStatus til '1' (=going)
		//timerStatus_3 = '1';
		TCNT3 = (0xFFFF-16000);
		while ((TIFR3 & (1<<0)) == 0)
		{
			PORT &= ~(1<<PINNR);
		}
		TCCR3B = 0;
		TIFR3 = 1<<0;
		//timerStatus_3 = '0';
}

void ventPaaZC()
{
	while(ZCDetected_ == 0)	{}
}

