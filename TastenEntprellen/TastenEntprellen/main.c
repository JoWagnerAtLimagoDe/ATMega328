/*
 * TastenEntprellen.c
 *
 * Created: 10.02.2018 17:11:15
 * Author : Joachim
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/interrupt.h>

static volatile uint16_t flag = 0;
static volatile uint16_t increment = 0;


ISR (TIMER0_COMPA_vect)  // timer0 overflow interrupt
{
	flag = 0;
	//TCNT0 = 90;
	//PORTB=~PORTB;
}


ISR (INT0_vect)
{
	if (flag == 0) {
		flag = 1;
		//TCNT0 = 90;
		TCNT0 = 0;
		PORTB=~PORTB;
		
	}
	
	
	
	 
	 
	
}


int main(void)
{
	
	DDRB=0xFF;
	PORTB=0xFF;
	
	DDRD &= ~(1 << DDD2);     // Clear the PD2 pin
	// PD2 (PCINT0 pin) is now an input

	PORTD |= (1 << PORTD2);    // turn On the Pull-up
	// PD2 is now an input with pull-up enabled
	
	 // Set the Timer Mode to CTC
	 //TCCR0A |= (1 << WGM01);

	 // Set the value that you want to count to
	 //OCR0A = 156;

	 TIMSK0 |= (1 << OCIE0A);    //Set the ISR COMPA vect

	


	 TCCR0B |= (1 << CS02) | (1 << CS00);
	 // set prescaler to 1024 and start the timer

	EICRA |= (1 << ISC01)|(1 << ISC00);    // set INT0 to trigger on rising edge

	EIMSK |= (1 << INT0);     // Turns on INT0
	
	sei();                    // turn on interrupts
	
	while(1)
	{
		
	}
}




