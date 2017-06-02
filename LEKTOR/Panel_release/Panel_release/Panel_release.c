#include "Panel.h"
#include "uart.h"

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	char input = 'B';
	char temp;
	initPorts();
	initInterrupt();
	InitUART(9600, 8, 'N');
	//sei () ; // Enable the Global Interrupt Enable flag so that interrupts can be processed
	
	while (1)
	{
		// Wait for new character received
		while ( (UCSR0A & (1<<7)) == 0 )
		{
			setInitials("H", "H", 'A');
		}
		// Then return it
		input = UDR0;
		setLED(input);
	}

	return 0;
}