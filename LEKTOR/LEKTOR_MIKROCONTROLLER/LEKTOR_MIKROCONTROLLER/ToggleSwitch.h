///////////////////////////////////////////////////////////////////////
///						- ToggleSwitch -							///
///				 Af Susanne, Patrick og Kasper						///
///	  Denne klasse initierer ToggleSwitch og overvåger dens status	///
///////////////////////////////////////////////////////////////////////
#pragma once
#include "avr/io.h"

//Variables
volatile char tilstand_;

char register___;
short int port___;

//Functions
void initToggleSwitch(char register_, short int port);
char toggleSwitchStatus();
