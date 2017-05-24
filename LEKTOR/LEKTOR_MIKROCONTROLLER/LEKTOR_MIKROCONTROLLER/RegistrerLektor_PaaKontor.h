///////////////////////////////////////////////////////////////
///				- RegistrerLektor_PaaKontor -				///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at sætte lektors-		///
///		status til paa Kontor								///
///////////////////////////////////////////////////////////////

#pragma once

//Variables
char lektortilStede_ = '0'; // Variablen her fortæller om lektor pt. er til stede på kontoret. Hvis ikke '1', er lektor IKKE til stede.

//Functions
void skiftLEDTilstand_PaaKontor(char tilStede);
void lektorStatus_PaaKontor(char sensorInput);