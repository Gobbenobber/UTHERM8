///////////////////////////////////////////////////////////////
///							- Sensor -						///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at checke lektors-		///
///		status via sensor									///
///////////////////////////////////////////////////////////////

#pragma once
#include "avr/io.h"
//Functions

void initSensor(char register__, short int pin);
char kontorStatus();

