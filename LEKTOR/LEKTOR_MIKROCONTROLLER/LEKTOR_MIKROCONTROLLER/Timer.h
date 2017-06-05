/*
//  $$$$$$$$\ $$\                                        
//  \__$$  __|\__|                                      
//     $$ |   $$\ $$$$$$\$$$$\   $$$$$$\   $$$$$$\       
//     $$ |   $$ |$$  _$$  _$$\ $$  __$$\ $$  __$$\    
//     $$ |   $$ |$$ / $$ / $$ |$$$$$$$$ |$$ |  \__|     
//     $$ |   $$ |$$ | $$ | $$ |$$   ____|$$ |      
//     $$ |   $$ |$$ | $$ | $$ |\$$$$$$$\ $$ |         
//     \__|   \__|\__| \__| \__| \_______|\__|     
----------------------------------------------
 */ 


///////////////////////////////////////////////////////////////
///						  - Timer_1 -						///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at lave en timer		///
///////////////////////////////////////////////////////////////

#pragma once
#include "avr/interrupt.h"
#include "avr/io.h"

//Functions
int returnerTimerStatus();
void setTimer();
void resetTimer();

