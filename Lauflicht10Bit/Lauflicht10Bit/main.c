/*
* LauflichtMit10Bit.c
*
* Created: 13.02.2018 08:42:28
* Author : syscgw1300
*/

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

static int8_t direction;
static uint8_t aktBit;

static inline void clearOutput() {
	PORTD &= 0b11000011;
	PORTB &= 0b11000000;
}

static inline void setSingleBit(uint8_t bit) {
	if(bit < 0 || bit>9) return;
	if (bit <= 5)
		PORTB |= (1 << bit);
	else
		PORTD |= (1 << ((bit%6)+2));
}


static inline void setup()
{
	DDRB = 0b00111111;
	DDRD = 0b00111100;
	PORTD = 0b00000011;
	direction = 1;
	aktBit = 0;
}

static inline void mainloop()
{
	clearOutput();
	for(int i = 0; i < 2; i ++){
		setSingleBit(aktBit+i*direction);
	}
	
	
	aktBit+=direction;
	if(aktBit < -1 || aktBit > 9)
		direction *= -1;
		
	_delay_ms(50);
}

int main(void)
{
	setup();
	while (1)
	{
		mainloop();
	}
}

