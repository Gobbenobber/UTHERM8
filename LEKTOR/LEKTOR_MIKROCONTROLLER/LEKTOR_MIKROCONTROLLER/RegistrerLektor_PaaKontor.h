///////////////////////////////////////////////////////////////
///				- RegistrerLektor_PaaKontor -				///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at sætte lektors-		///
///		status til paa Kontor								///
///////////////////////////////////////////////////////////////

#pragma once

//Variables
char tilStede_ = 'a'; // Variablen her fortæller om lektor pt. er til stede på kontoret. Hvis ikke, er kan IKKE til stede.

//Functions
void skiftLEDTilstand_PaaKontor(char);
void lektorStatus_PaaKontor(char*);