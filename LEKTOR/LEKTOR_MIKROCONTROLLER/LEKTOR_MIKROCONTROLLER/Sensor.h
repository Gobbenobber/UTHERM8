///////////////////////////////////////////////////////////////
///							- Sensor -						///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at checke lektors-		///
///		status via sensor									///
///////////////////////////////////////////////////////////////

#pragma once
#include "avr/io.h"

//Variables
volatile char lektorDetected_ = '0';
char register__;
short int port__;

//Functions

void initSensor(char register_, short int port);
char kontorStatus();

