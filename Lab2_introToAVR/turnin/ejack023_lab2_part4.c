/*	Name & E-mail: Ethan Jackson ejack023@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template 
 * 	or example code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // A is input, writes 0xFF to A
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00; // B is output, initialize B to 0x00
	unsigned char aWeight = 0x00;
	unsigned char bWeight = 0x00;
	unsigned char cWeight = 0x00;
	unsigned short totWeight = 0x00;
    while (1) {
	aWeight = PINA;
	bWeight = PINB;
	cWeight = PINC;
	totWeight = aWeight + bWeight + cWeight;
	if (totWeight > 140) PORTD = PORTD | 0x01;
	else PORTD = PORTD & 0xFE;
	if (aWeight-cWeight > 80 || aWeight-cWeight < -80) PORTD = PORTD | 0x02;
	else PORTD = PORTD & 0xFD;
	PORTD = (PORTD & 0x03) | (totWeight & 0xFC);
    }
    return 0;
}
