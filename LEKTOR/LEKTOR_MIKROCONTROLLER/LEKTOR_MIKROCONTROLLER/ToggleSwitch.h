///////////////////////////////////////////////////////////////////////
///						- ToggleSwitch -							///
///				 Af Susanne, Patrick og Kasper						///
///	  Denne klasse initierer ToggleSwitch og overvåger dens status	///
///////////////////////////////////////////////////////////////////////
#pragma once
#include "avr/io.h"

//Functions
void initToggleSwitch(char register__, short int pin);
char toggleSwitchStatus();
