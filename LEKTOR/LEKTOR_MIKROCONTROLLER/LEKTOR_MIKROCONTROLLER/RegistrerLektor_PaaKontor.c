/*

	____    ______           _   __            _
	\ \ \   | ___ \         | | / /           | |
	 \ \ \  | |_/ __ _  __ _| |/ /  ___  _ __ | |_ ___  _ __
	  \ \ \ |  __/ _` |/ _` |    \ / _ \| '_ \| __/ _ \| '__|
	   \ \ \| | | (_| | (_| | |\  | (_) | | | | || (_) | |
		\_\_\_|  \__,_|\__,_\_| \_/\___/|_| |_|\__\___/|_|
		---------------------------------------------------

- Indeholder information om lektors tilstedeværelse på kontoret.
- Skrevet af Kasper, Susanne og Patrick.

 */ 
 #include "RegistrerLektor_PaaKontor.h"
 #include "ToggleSwitchLED.h"


 //Skift LEDTilstand for ToggleSwitchLED baseret på, hvorvidt lektor er til stede (parametiseret)
 void skiftLEDTilstand_PaaKontor(char tilStede)
 {

	if (tilStede == '1')
	{
	setToggleSwitchLED('0');
	}
	else
	{
	setToggleSwitchLED('1');
	}

 }

 //Registrér om den afsendte streng indikerer at lektoren er på kontoret.
 void lektorStatus_PaaKontor(char* afsendtStreng)
 {
	if (afsendtStreng[2] == 't') //bemærk 't' for 'tilstede'
	{
	tilStede_ = '1';
	}
	else
	{
	tilStede_ = '0';
	}

 }
