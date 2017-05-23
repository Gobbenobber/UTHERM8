///////////////////////////////////////////////////////////////
///					- RegistrerLektor_Optaget -				///
///				   Af Susanne, Patrick og Kasper			///
///		Denne klasse har til opgave at s�tte lektors-		///
///		status til optaget og reagere hvis han/hun ikke		///
///		l�ngere er optaget.									///
///////////////////////////////////////////////////////////////

#ifndef REGISTRERLEKTOR_OPTAGET_H_
#define REGISTRERLEKTOR_OPTAGET_H_

//Variables
volatile char lektorOptaget = '0';

//Functions
void skiftLEDTilstand_Optaget(char);
void lektorStatus_Optaget(char*);
void setTimer();
void resetTimer();
void timerStatus();
void initTimer0();

#endif /* REGISTRERLEKTOR_OPTAGET_H_ */