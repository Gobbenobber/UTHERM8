 #include "X10_Receiver.h"
 #include "zeroCrossDetector.h"

 volatile int state;
 int firstCheck = 1;
 int i;
 int j;
 static unsigned char receive[5];
 static unsigned char firstByteReceived;
 
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

void start100usDelay()
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

unsigned char* receiveX10Message()
{
	for (j = 7; j >= 0; j--)
	{	
		start100usDelay();
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
		start100usDelay();
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
				start100usDelay();
				start100usDelay();
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