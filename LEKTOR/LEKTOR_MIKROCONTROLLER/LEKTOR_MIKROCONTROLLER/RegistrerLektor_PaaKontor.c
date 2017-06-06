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
 #include "Sensor.h"
 #include "ToggleSwitchLED.h"
 #include "Timer.h"

 //Skift LEDTilstand for ToggleSwitchLED baseret på, hvorvidt lektor er til stede (parametiseret)


 //Registrér om den afsendte streng indikerer at lektoren er på kontoret.
 void lektorStatus_PaaKontor()
 {
	if (kontorStatus() == '1') 
	{
		lektortilStede_ = '1';
		//skiftLEDTilstand_PaaKontor();
	}
	else
	{
		lektortilStede_ = '0';
		//skiftLEDTilstand_PaaKontor();
	}

 }


  void skiftLEDTilstand_PaaKontor()
  {
	  if (lektortilStede_ == '1' && returnerTimerStatus() == 0)
	  {
		  setToggleSwitchLED('0');
	  }
	  else
	  {
		  setToggleSwitchLED('1');
	  }
  }