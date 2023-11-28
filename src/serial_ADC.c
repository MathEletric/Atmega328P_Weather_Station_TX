#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdio.h>

void Inicia_USART(long unsigned int baud_rate)
{
	int ubrr;
	ubrr = ((F_CPU) / (8 * baud_rate)) - 1;

	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0A |= (1 << U2X0);

	UCSR0B |= ((1 << RXEN0) | (1 << TXEN0));

	UCSR0C &= ~((1 << UMSEL01) | (1 << UMSEL00));
	UCSR0C &= ~((1 << UPM01) | (1 << UPM00));
	UCSR0C &= ~(1 << USBS0);

	UCSR0C &= ~(1 << UCSZ02);
	UCSR0C |= ((1 << UCSZ01) | (1 << UCSZ00));

	UCSR0B |= (1 << RXCIE0);  // Habilita a interrupção da recepção da USART
}


void enviar_dado(unsigned char data){
	while (!(UCSR0A & (1 << UDRE0)));  // Aguarda o buffer esvaziar
	UDR0 = data;  // Envia o dado
}

void enviar_string(const char *s){
	while (*s){
		enviar_dado(*s++);
	}
}

// Configuração e leitura do ADC
void initADC(){
  	ADMUX |= (0 << REFS1) | (1 << REFS0);; // Configura VCC como referência
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Liga o ADC e configura prescaler
}

int readADC(int channel){
	ADMUX = (ADMUX & 0xF8) | channel; // Seleciona o canal do ADC (AD0)
	ADCSRA |= (1 << ADSC); // Inicia a conversão
	while (ADCSRA & (1 << ADSC)); // Espera a conversão completar
	return ADC;
}

