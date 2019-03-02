/*
 * Config_timer_e_interrupcao.c
 *
 * Created: 19/05/2018 13:41:37
 * Author : Emerson
 */ 
/*
 * Configura��o dos TIMERS:
 *
 * Rotina de interrup��o: ISR(TIMERx_OVF_vect), x = 0,1,2 --> Estouro de bits, toda vez que passa do 255 (8bist) vai pra essa rotina
 *
 *TCCR2A = Registrador que controla o timer 0x00 -> modo de opera��o normal
 *TCCR2B = Config o prescaler, divide a freq pra contar tempos maiores
 *TCNT2 = Contem o valor da contagem
 *TIMSK2 = habilita a interrup��o por estouro
 *
*/

#define  F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>

int counter;                           //Variavel para contagem

ISR(TIMER0_OVF_vect)                   // Quando estoura os 255 , ROUTINA DE INTERRUP��O
{
		counter++;
		
		if(counter == 24)
		{
			PORTB ^= 0x01;				//Inverte o bit PD0 (PORTD = PORTD xor 0x01)
			counter = 0x00;				//Zera o counter
		}
}

int main(void)
{
	
	cli();								//Desabilita a interrup��o global
	
	DDRB |= (1<<0);						//O PB0 ser� sa�da digital
	PORTB &= ~(1<<0);					//Inicia o PD0 em n�vel low
	
	TCNT0 =  0x00;						//Inicia o timer0 em 0
	TCCR0B = 0x04;						//Configura o prescaler para 1:256
	TIMSK0 = 0x01;						//Habilita a interrup��o por estouro do TMR0
	
	sei();								//Habilitar a interrup��o global 
	
	
/*
   Queremos um per�odo de 2000ms
   
   Troca de estado de PD0 , 1000ms
   
   
   Ciclo de M�quina
   
   Em PIC 1/clock/4
   
   Em 8051 1/ clock/12
   
   Em AVR 1/1600000
   
   
   Ciclo de m�quina: 1/16Mhz = 62,5ns
   
   
   Estouro = timer0 x prescaler x ciclo de m�quina = 4,08ms   cada comando tem leva esse tempo para ser realizado
              255       256          62,5ns   

   Troca de estado = Estouro x Counter
   
   1000ms = 4,08ms x counter
   
   counter = 1000/4,08 = 245
   
   p/ 100ms counter = 24 

*/
	
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

