/*
 * 004_Pot_LED.c
 *
 * Created: 26/05/2018 15:36:56
 * Author : Emerson Conceição
 */ 

#include <avr/io.h>
#include <util/delay.h> // Inclui biblioteca de delay
#define F_CPU 16000000 //16Mhz
/************************************************************************/
/* Define Macros, que podem ser usadas no programa                      */
/************************************************************************/
#define LED_ON  PORTB |= (1<<0);    // Ou PORTB |= (1<<PORTBn), Nesse caso é o PORTB0, Liga o led
#define LED_OFF  PORTB &= ~(1<<0);  //Desliga o Led
#define LED_TOGGLE PINB |= (1<<0);  // Pisca o led

int main(void)
{
    DDRB |= (1<<0);   // LED como entrada
	DDRC &= ~(1<<0);  // pot como entrada digital
	
	PORTB &= ~(1<<0); // começa com led apagado

    while (1) 
    {
		if ((PINC & (1<<PINC0))) //bot pressionado
		{
			LED_ON
		}
		else{
			LED_OFF
		}
    }
	
}

