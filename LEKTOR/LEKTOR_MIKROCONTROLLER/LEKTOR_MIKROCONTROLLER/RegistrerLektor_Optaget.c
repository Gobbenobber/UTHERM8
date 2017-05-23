

 // Global interrupt enable
 
 void skiftLEDTilstand_Optaget(char lektorOptaget)
{
	if (lektorOptaget == '0')
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

void lektorStatus_Optaget(char*)
{
	

}