///////////////////////////////////////////////////////////////
///							- Sensor -						///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at checke lektors-		///
///		status via sensor									///
///////////////////////////////////////////////////////////////

#ifndef SENSOR_H_
#define SENSOR_H_

//Variables
volatile char lektorDetected_ = '0';

//Functions
char kontorStatus();

#endif /* SENSOR_H_ */