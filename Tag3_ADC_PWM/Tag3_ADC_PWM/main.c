/*
 * Tag3_ADC_PWM.c
 *
 * Created: 14.02.2018 11:16:36
 * Author : fp50slw
 */ 


#include <avr/io.h>

#include <avr/interrupt.h>

ISR(ADC_vect)

{

	OCR0A = ADCH;          // only need to read the high value for 8 bit

	// REMEMBER: once ADCH is read the ADC will update

	// if you need the value of ADCH in multiple spots, read it into a register

	// and use the register and not the ADCH

}

int main(void)
{
	
	ADMUX = 0;                // use ADC0
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX |= (1 << ADLAR);    // Right adjust for 8 bit resolution

	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 128 prescale for 16Mhz
	ADCSRA |= (1 << ADATE);   // Set ADC Auto Trigger Enable

	ADCSRB = 0;               // 0 for free running mode

	ADCSRA |= (1 << ADEN);    // Enable the ADC

	ADCSRA |= (1 << ADIE);    // Enable Interrupts

	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	sei();    // Thanks N, forgot this the first time =P





	
	DDRD |= (1 << DDD6);
	OCR0A = 64;
	// set PWM for 50% duty cycle

	TCCR0A |= (1 << COM0A1);
	// set none-inverting mode
	TCCR0A |= (1 << WGM01) | (1 << WGM00);   //WGM02 oder 1
	// set fast PWM Mode

	TCCR0B |= (1 << CS01);
	// set prescaler to 8 and starts PWM

	while (1);
	{
		// we have a working Fast PWM

	}
}