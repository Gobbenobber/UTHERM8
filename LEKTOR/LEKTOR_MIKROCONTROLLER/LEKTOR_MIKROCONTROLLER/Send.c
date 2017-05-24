//Header
#include "Send.h"

// 8 data bit, no parity, 1 stop bit
void sendCharSW(char Tegn)
{
	// Main-loop: Toggle LED7 hvert sekund
	unsigned char i;
	unsigned char x = Tegn;
	// Start bit
	PORT &= ~(1<<PINNR);
	_delay_us(NO_us);
	// 8 data bits (LSB first)
	for (i = 0; i<8; i++)
	{
		if(x & 0b00000001)
			PORT |= (1<<PINNR);
		else
			PORT &= ~(1<<PINNR);
		_delay_us(NO_us);
		x = x>>1;
	}
	PORT |= (1<<PINNR);
	_delay_us(NO_us);
	//Test ###DUNNO what the stopbit is###
	//PORT &= ~(1<<PINNR);
}