 #include "X10_Master.h"
 #include "RegistrerLektor_Optaget.h"
 #include "RegistrerLektor_PaaKontor.h"
 #include "Timer.h"
 #include "zeroCrossDetector.h"

 volatile int state;
 int firstCheck = 1;

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

void receiveBurst(char* buffer)
{
	//sæt ZDDetected til 0 hvis der er ZeroCross.
	if (ZCDetected_ == 1)
	{
		ZCDetected_ = 0;
	}
	//PORTB = OUTPUT -- lad 120kHz signal fra OCRB komme ud.
	for (int i = 0; i < 3; i++)
	{
		if (validateStartByte(receive[0]) == 't')
		{
			for (int j = 0; j < 9; j++)
			{
				ventPaaZC();
				start500usDelay();
				if ((j == 8) && (PORT & 1))
				{
					
				}
				else
				{
					i--;
				}
				if (PORT & 1)
				{
					receive[i] |= 1 << j;
				}
				else
				{
					receive[i] &= ~(1 << j);
				}
			}
		}
		else
		{
			for (int j = 0; j < 8; j++)
			{
				ventPaaZC();
				start500usDelay();
				if (PORT & 1)
				{
					receive[0] |= 1 << j;
				}
				else
				{
					receive[0] &= ~(1 << j);
				}
			}
			i = 0;
		}
	}

	//Sæt PORTH til input igen.
	DDR = 0;
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
