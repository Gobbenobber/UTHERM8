
///////////////////////////////////////////////////////////////////////
///						- ToggleSwitchLED -							///
///				 Af Susanne, Patrick og Kasper						///
///			Denne klasse initierer ToggleSwitchLED					///
///	og indeholder metode til at sætte LED'ens status dens status	///	
///////////////////////////////////////////////////////////////////////
#pragma once
#include "avr/io.h"

//Functions
void initToggleSwitchLED(char register__, short int port);
void setToggleSwitchLED(char bool_);

