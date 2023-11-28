#include<avr/io.h>
//Configuração e escolha do canal
void ADC_init(int channel){
	ADMUX = (ADMUX & ~(1<<7)) | (1<<6); //VCC como referência.
	ADMUX = (ADMUX & 0xF8) | channel; //Define o canal.

	ADCSRA = ADCSRA | ((1<<0) + (1<<1) + (1<<0)); //Define prescaler em 128 (9,6 Ksps)
	ADCSRA |= (1<<7); //Enable.	 
}

int ADC_read(){
	ADCSRA |= (1 << ADSC); //Inicia a conversão.
	while (ADCSRA & (1 << ADSC)); //Espera a conversão completar.
	return ADC;
}