#include "Panel.h"

#include <util/delay.h>


int main(void)
{
	char input = 'B';
	initPorts();
	initInterrupt();
	InitUART(9600, 8, 'N');
	
	while (1)
	{
		SendString("Bøllemis");
		//input = ReadChar();
		//setLED(input);
		//setInitials("H", "H", 'A');
	}

	return 0;
}

