#include "Panel.h"

#include <util/delay.h>


int main(void)
{
	initPorts();
	initInterrupt();
	
	while (1)
	{
		setInitials("B", "B", 'A');
	}

	return 0;
}

