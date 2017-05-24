/*
				Timer2.h
----------------------------------
Driver til timer 2 delay op til max. 51 us.
----------------------------------

Created: 13-12-2016 10:52:59
Modified: 23-05-2017
Author: Batuik

 */ 

#pragma once
#include <avr/io.h>

void T2Delay(int delay_us); //max 51 uS delay.