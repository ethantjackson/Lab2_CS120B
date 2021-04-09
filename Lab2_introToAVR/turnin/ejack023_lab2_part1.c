/*	Author: ejack023
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // A is input, writes 0xFF to A
	DDRB = 0xFF; PORTB = 0x00; // B is output, initialize B to 0x00
	unsigned char lightDetected = 0x00;
	unsigned char doorOpen = 0x00; 
    while (1) {
	lightDetected = PINA & 0x02;
	doorOpen = PINA & 0x01;
	if (!lightDetected && doorOpen) PORTB = 0x01;
	else PORTB = 0x00;
    }
    return 0;
}
