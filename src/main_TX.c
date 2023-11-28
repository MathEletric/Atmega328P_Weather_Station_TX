#define F_CPU 16000000
#define BAUD 9600
#define MY_UBRR0 (F_CPU/16*BAUD) - 1
#define ADC0 0;
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdio.h>

int main(void){
	pinConfig();
	USART_init(MY_BOUD);
	ADC_init(ADC0);

	sei(); //SREG |= (1<<7);

	while (1){
		if(!(PINB & (1<<0))){
		while(!(PINB & (1<<0)));
			void NTC_sensor();
		}		
	}
	return 0;
}