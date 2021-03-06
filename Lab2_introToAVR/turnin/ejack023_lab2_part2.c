/*	Name & E-mail: Ethan Jackson ejack023@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 2  Exercise 2
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
	DDRC = 0xFF; PORTC = 0x00; // B is output, initialize B to 0x00
	unsigned char cntavail = 0x00;
    while (1) {
	cntavail = 0x00;
	if (!(PINA & 0x08)) ++cntavail;
	if (!(PINA & 0x04)) ++cntavail; 	
	if (!(PINA & 0x02)) ++cntavail; 	
	if (!(PINA & 0x01)) ++cntavail; 	
	PORTC = cntavail;
    }
    return 0;
}
