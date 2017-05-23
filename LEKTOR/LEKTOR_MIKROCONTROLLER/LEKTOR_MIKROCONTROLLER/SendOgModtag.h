//Packages
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>


//Constants
#define NO_us 80000/BAUD
#define DDR   DDRB
#define PORT  PORTB
#define PINNR 0
#define PINNR_2 8
#define BAUD  9600

// 8 data bit, no parity, 1 stop bit
void SendCharSW(char Tegn);

// 8 data bit, no parity, 1 stop bit
char ReadCharSW();