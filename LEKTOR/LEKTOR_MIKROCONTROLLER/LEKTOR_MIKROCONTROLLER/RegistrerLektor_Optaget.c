
#include "RegistrerLektor_Optaget.h"
#include "ToggleSwitch.h"
#include "ToggleSwitchLED.h"
 
void lektorStatus_Optaget()
{
	if (toggleSwitchStatus() == '1') //bemærk, '1' for "optaget".
	{
	lektorOptaget_ = '1';
	//skiftLEDTilstand_Optaget();
	}

	else
	{
	lektorOptaget_ = '0';
	//skiftLEDTilstand_Optaget();
	}

}

 void skiftLEDTilstand_Optaget()
 {
	 if (lektorOptaget_ == '0')
	 {
		 setToggleSwitchLED('0');
	 }

	 else
	 {
		 setToggleSwitchLED('1');
	 }

 }