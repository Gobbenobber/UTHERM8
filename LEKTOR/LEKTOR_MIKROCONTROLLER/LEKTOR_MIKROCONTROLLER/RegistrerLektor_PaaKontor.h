///////////////////////////////////////////////////////////////
///				- RegistrerLektor_PaaKontor -				///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at s�tte lektors-		///
///		status til paa Kontor								///
///////////////////////////////////////////////////////////////

#pragma once
#include "ToggleSwitch.h"
#include "Sensor.h"

//Variables
char tilStede_ = 'a';

//Functions
void skiftLEDTilstand_PaaKontor(char);
void lektorStatus_PaaKontor(char*);
