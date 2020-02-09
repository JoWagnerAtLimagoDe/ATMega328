/*
 * Uart.c
 *
 * Created: 15.02.2018 12:55:08
 * Author : syscgw1300
 */ 
#define F_CPU 16000000L

#include<avr/io.h>   
#define USART_BAUDRATE 9600 
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

void putChar(uint8_t character) {
	// wait until the port is ready to be written to
	while( !( UCSR0A & ( 1 << UDRE0 ) )  );
	// write the byte to the serial port
	UDR0 = character;
}

uint8_t receiveChar() {
	// wait until a byte is ready to read
	while( ( UCSR0A & ( 1 << RXC0 ) ) == 0 ){}
	// grab the byte from the serial port
	return UDR0;	
}
   
void putString(char * text) {
	while(*text) {
		putChar(*text++);
	}
}
   
int main(void){  
	char recieved_byte;     
	UCSR0B |= (1<<RXEN0)  | (1<<TXEN0);  // Register f�r Sendenund empfangen
	UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01);  // Register 8-Bitmodus
	UBRR0H  = (BAUD_PRESCALE >> 8);  // Highbyte
	UBRR0L  = BAUD_PRESCALE;         // Lowbyte
	putString("Hallo Putty\n\r");      
	while(1){   
		   
			recieved_byte = receiveChar();
		 
			putChar(recieved_byte);
			
		
 
	}     
	return 0;   /* never reached */
}
