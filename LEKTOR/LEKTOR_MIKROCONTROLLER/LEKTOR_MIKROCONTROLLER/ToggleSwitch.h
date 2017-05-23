///////////////////////////////////////////////////////////////////////
///						- ToggleSwitch -							///
///				 Af Susanne, Patrick og Kasper						///
///	  Denne klasse initierer ToggleSwitch og overvåger dens status	///
///////////////////////////////////////////////////////////////////////
#pragma once
#include "avr/io.h"

//Variables
volatile char tilstand_ = 0;

char register__;
short int port__;

//Functions
void initToggleSwitch(char register_, short int port);
char toggleSwitchStatus();
