///////////////////////////////////////////////////////////////
///				- RegistrerLektor_PaaKontor -				///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at s�tte lektors-		///
///		status til paa Kontor								///
///////////////////////////////////////////////////////////////

#pragma once

//Variables
volatile char lektortilStede_; // Variablen her fort�ller om lektor pt. er til stede p� kontoret. Hvis ikke '1', er lektor IKKE til stede.

//Functions
//void skiftLEDTilstand_PaaKontor();
void lektorStatus_PaaKontor();