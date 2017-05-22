#ifndef TOGGLESWITCH_H_
#define TOGGLESWITCH_H_

//Variables
volatile char tilstand;

//Functions
void initToggleSwitch(int port, char register);
char toggleSwitchStatus();

#endif /* TOGGLESWITCH_H_ */