//Packages
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

//Local Constants
#define NO_us 800000/BAUD
#define DDR   DDRB
#define PORT  PORTB
#define PINNR 0
#define PINNR_2 0
#define BAUD  9600

// 8 data bit, no parity, 1 stop bit
void sendCharSW(char Tegn);