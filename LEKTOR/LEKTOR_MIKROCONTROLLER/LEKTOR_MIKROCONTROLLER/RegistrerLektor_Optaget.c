
#include "RegistrerLektor_Optaget.h"
#include "ToggleSwitchLED.h"
 
 void skiftLEDTilstand_Optaget(char lektorOptaget)
{
	if (lektorOptaget == '0')
	{
	setToggleSwitchLED('0');
	}

	else 	
	{
	setToggleSwitchLED('1');
	}

}

void lektorStatus_Optaget(char toggleSwitchInput)
{
	if (toggleSwitchInput == '1') //bemærk, '1' for "optaget".
	{
	lektorOptaget_ = '1';
	}

	else
	{
	lektorOptaget_ = '0';
	}

}