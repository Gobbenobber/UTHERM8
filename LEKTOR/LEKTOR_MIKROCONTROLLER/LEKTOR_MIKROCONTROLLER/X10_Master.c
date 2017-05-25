/*
 * CFile1.c
 *
 * Created: 26-05-2017 01:04:53
 *  Author: Batuik
 */ 


 #include "X10_Master.h"
 #include "RegistrerLektor_Optaget.h"
 #include "RegistrerLektor_PaaKontor.h"
 #include "Timer_1.h"

 volatile int state;
 int firstCheck = 1;


 void opdaterKommando()
 {
	 if (lektorOptaget_ == '0' && lektortilStede_ == '0')
	 {
		 if ((state = 00) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 aendring_ = 1;
			 COMMAND = 'V';		// V indikerer at lektor er væk!
		 }
		 state = 00;
	 }
	 else if ((lektorOptaget_ == '0') && (lektortilStede_ == '1'))
	 {
		 if ((state = 01) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 aendring_ = 1;
			 COMMAND = 'T';		// T Indikerer at lektor er tilstede
			 state = 01;
		 }
	 }
	 else if ((lektorOptaget_ == '1') && (lektortilStede_ == '0'))
	 {
		 if ((state = 10) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 aendring_ = 1;
			 COMMAND = 'O';		// O indikerer at lektor har benyttet ToggleSwitch (=Optaget)
			 state = 10;
		 }
	 }
	 else if ((lektorOptaget_ == '1') && (lektortilStede_ == '1'))
	 {
		 if ((state = 11) && (firstCheck != 1))
		 {
			 aendring_ = 0;
		 }
		 else
		 {
			 if (returnerTimerStatus() == 0)
			 {
				 setTimer();
			 }
			 aendring_ = 1;
			 COMMAND = 'O';		// O indikerer at lektor har benyttet ToggleSwitch (=Optaget)
			 state = 11;
		 }
	 }

	 if (firstCheck == 1)
	 {
		 firstCheck = 0;
	 }

 }