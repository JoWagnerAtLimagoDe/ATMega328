/*
 * 11_WATCHDOG.c
 *
 * Created: 15.02.2018 19:46:58
 * Author : Joachim
 */ 

#include <avr/io.h>
#include <avr/wdt.h>

int main(void)
{
    wdt_enable(WDTO_15MS);
	
    while (1) 
    {
		wdt_reset();
    }
}

