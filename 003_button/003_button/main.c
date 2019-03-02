/*
 * 003_button.c
 *
 * Created: 25/05/2018 23:36:44
 * Author : Emerson Conceição
 * Piscando led com botão
 */ 

#define F_CPU 16000000   // Clock 16Mhz
#include <avr/io.h>
#include <util/delay.h>  // inclui lib para usar delay
unsigned char i;

int main(void)
{
    DDRB &= ~(1<<0);      // Seta PB0 como entrada
	DDRB |= (1<<1);      // Seta PB1 como saida
	PORTB &= ~(1<<1);    // Desliga LED
	
    while (1) 
    {
	i = PINB;	
	 if (PINB == 0 ) {
	PORTB |= (1<<1);
	_delay_ms(100);	
	}
	else{
	PORTB &= ~(1<<1);	
	_delay_ms(100);	
	}
    }
}

