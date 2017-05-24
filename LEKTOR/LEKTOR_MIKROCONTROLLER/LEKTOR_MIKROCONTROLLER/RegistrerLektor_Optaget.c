

 // Global interrupt enable
 
 void skiftLEDTilstand_Optaget(char lektorOptaget)
{
	if (lektorOptaget == '1')
	{
	lektorOptaget_ = '0';
	setToggleSwitchLED('0');
	}
	else 	
	{
	lektorOptaget_ = '1';
	setToggleSwitchLED('1')
	}

}

void lektorStatus_Optaget(char* notSure)
{
	if (notSure[2] == 'P')
	{
	lektorOptaget_ = '1';
	}

	else
	{
	lektorOptaget_ = '0';
	}

}