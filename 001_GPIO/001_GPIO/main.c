/*
 * 001_GPIO.c
 *
 * Created: 25/05/2018 23:06:19
 * Author : Emerson Conceição
 * Blink Led
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB  |=  (1<<0);  // Seta como saída
	PORTB &= ~(1<<0);  // Inicia desligado
    while (1) 
    {
	
	PORTB |=  (1<<0);    // Inverte o estado
	_delay_ms(1000);   // espera 1 seg
	PORTB &= ~(1<<0);    // Inverte o estado
	_delay_ms(1000);   // espera 1 seg
		
    }
}

