 #include "X10_Master.h"
 #include "zeroCrossDetector.h"

 volatile int state;
 int firstCheck = 1;
 int i;
 int j;
 unsigned static char receive[4];
 unsigned static char firstByteReceived;

char validateStartByte(char val)
{
	// val = 0b11101110
	if (val & 0b11101110)
		return 't';
	else
		return 'f';
}

void start500usDelay()
{
	// Timer3: Normal mode, PS = 0
	TCCR3A = 0b00000000;
	TCCR3B = 0b00000001;
	// Overflow hvert MS.
	//Sæt timerStatus til '1' (=going)
	//timerStatus_3 = '1';
	TCNT3 = (0xFFFF-32000);
	while ((TIFR3 & (1<<0)) == 0)
	{}
	TCCR3B = 0;
	TIFR3 = 1<<0;
	//timerStatus_3 = '0';
}

void start1msDelay()
{
	// Timer3: Normal mode, PS = 0
	TCCR3A = 0b00000000;
	TCCR3B = 0b00000001;
	// Overflow hvert MS.
	//Sæt timerStatus til '1' (=going)
	//timerStatus_3 = '1';
	TCNT3 = (0xFFFF-16000);
	while ((TIFR3 & (1<<0)) == 0)
	{}
	TCCR3B = 0;
	TIFR3 = 1<<0;
	//timerStatus_3 = '0';
}

void start400usDelay()
{
	// Timer4: Normal mode, PS = 0
	TCCR4A = 0b00000000;
	TCCR4B = 0b00000001;
	// Overflow hvert MS.
	//Sæt timerStatus til '1' (=going)
	//timerStatus_3 = '1';
	TCNT4 = 63936;
	while ((TIFR4 & (1<<0)) == 0)
	{}
	TCCR4B = 0;
	TIFR4 = 1<<0;
	//timerStatus_3 = '0';
}

unsigned char* receiveBurst()
{
	while (!(PINF & (1 << 7)))
	{}

	for (j = 7; j >= 0; j--)
	{
		if (PINF & (1 << 7))
		{
			firstByteReceived |= 1 << j;
		}
		else
		{
			firstByteReceived &= ~(1 << j);
		}
		ventPaaZC();
		start1msDelay();
		start1msDelay();
		start400usDelay();
		start400usDelay();
	}

	if (firstByteReceived == 0b11101110)
	{
		for (i = 0; i < 5; i++)
		{
			if (i == 4)
			{
				receive[i] = '\0';
				break;
			}
			for (j = 7; j >= 0; j--)
			{
				if (PINF & (1 << 7))
				{
					receive[i] |= 1 << j;
				}
				else
				{
					receive[i] &= ~(1 << j);
				}
				ventPaaZC();
				start1msDelay();
				start1msDelay();
				start400usDelay();
				start400usDelay();
			}
		}
			
	}
return receive;
}

void ventPaaZC()
{
	ZCDetected_ = 0;
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

int pinStatus(){
	return PORT << PINNR;
}