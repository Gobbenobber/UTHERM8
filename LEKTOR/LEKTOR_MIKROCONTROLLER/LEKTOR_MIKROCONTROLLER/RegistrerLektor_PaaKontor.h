///////////////////////////////////////////////////////////////
///				- RegistrerLektor_PaaKontor -				///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at s�tte lektors-		///
///		status til paa Kontor								///
///////////////////////////////////////////////////////////////

#pragma once

//Variables
char tilStede_ = 'a'; // Variablen her fort�ller om lektor pt. er til stede p� kontoret. Hvis ikke, er kan IKKE til stede.

//Functions
void skiftLEDTilstand_PaaKontor(char);
void lektorStatus_PaaKontor(char*);