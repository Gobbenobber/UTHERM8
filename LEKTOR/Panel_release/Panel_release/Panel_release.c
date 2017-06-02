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
		input = ReadChar();
		SendChar(input);
		setLED(input);
		//setInitials("H", "H", 'A');
	}

	return 0;
}