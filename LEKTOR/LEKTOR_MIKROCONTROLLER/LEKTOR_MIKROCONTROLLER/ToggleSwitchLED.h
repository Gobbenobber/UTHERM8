#ifndef TOGGLESWITCHLED_H_
#define TOGGLESWITCHLED_H_

//Variables
volatile char LED_ON;

//Functions
void initToggleSwitchLED(int port, char register_);
void setToggleSwitchLED(char);

#endif /* TOGGLESWITCHLED_H_ */