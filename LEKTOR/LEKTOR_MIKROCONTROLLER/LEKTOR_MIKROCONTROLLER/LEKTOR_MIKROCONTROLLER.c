#include "Manchester.h"
#include "switch.h"
#include "uart.h"

	/* Test af Manchester.h */

int main(void) {

	InitUART(9600,8,'E');
	initSwitchPort();

	/* Streng som skal sendes via X10 som manchester kode */
	const unsigned char* henningtilstede = "AA";

	while (1)
	{

		if (switchStatus() != 0)
		{
			if (switchOn(0))
			{
			/* Test af stringToManchester() */

			SendString(stringToManchester(henningtilstede));
			freePtr();
			}

		}

	}




} 