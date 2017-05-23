///////////////////////////////////////////////////////////////
///					- RegistrerLektor_Optaget -				///
///				   Af Susanne, Patrick og Kasper			///
///		Denne klasse har til opgave at sætte lektors-		///
///		status til optaget og reagere hvis han/hun ikke		///
///		længere er optaget.									///
///////////////////////////////////////////////////////////////


#pragma once
#include "ToggleSwitch.h"
#include "Timer.h"

//Variables
volatile char lektorOptaget_ = '0';

//Functions
void skiftLEDTilstand_Optaget(char bool_);
void lektorStatus_Optaget(char*);


