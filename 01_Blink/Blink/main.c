/*
 * Blink.c
 *
 * Created: 05.02.2018 18:54:38
 * Author : Joachim
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>


int main(void)
{
    DDRB=0xFF;
    PORTB=0xFF;
    while (1)
    {
	    PORTB=0xFF;
	    _delay_ms(100);
	    PORTB=0;
	    _delay_ms(500);
	    
    }
}

