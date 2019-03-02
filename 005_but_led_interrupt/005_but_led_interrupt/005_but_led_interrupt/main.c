/*
 * 005_but_led_interrupt.c
 *
 * Created: 30/05/2018 19:45:37
 * Author : Emerson Conceição
 */ 

#include <avr/io.h>
#include <util/delay.h> // Inclui biblioteca de delay
#include <avr/interrupt.h>
#define F_CPU 16000000 //16Mhz
/************************************************************************/
/* Define Macros, que podem ser usadas no programa                      */
/************************************************************************/
#define LED_ON  PORTB |= (1<<0)   // Ou PORTB |= (1<<PORTBn), Nesse caso é o PORTB0, Liga o led
#define LED_OFF  PORTB &= ~(1<<0)  //Desliga o Led
#define LED_TOGGLE PINB |= (1<<0)  // Pisca o led
#define But !(PINC & (1<<PINC0))
#define LED_TOGGLE3 PINB |= (1<<3)  // Pisca o led

ISR(PCINT0_vect)
{
	if (But)
	{
		LED_ON;
	}
	else{
		LED_OFF;
	} 
	
}
int main(void)
{
    DDRB |= (1<<0);   // LED como saida
	DDRB |= (1<<3);
	DDRC &= ~(1<<0);  // pot como entrada digital
	
	PORTB &= ~(1<<0); // começa com led apagado
	PCMSK0 |= (1<<7); //Controle dos registradores, habilita com pin vai ter interrupção
	PCICR  |= (1<<0); //habilita interrupção
	
	sei(); // habilita dnv o interrupção SREG = registrador que q tem as flags de interrupção

    while (1) 
    {
		LED_TOGGLE3;
	}
		
	
}


