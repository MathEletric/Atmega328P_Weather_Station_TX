#include<avr/io.h>
//Inicia USART
void USART_init(unsigned int ubrr){
    UBRR0H = (unsigned char)(ubrr>>8); //Recebe MY_BOUD. Ajusta a taxa de transmissão.
    UBRR0L = (unsigned char)(ubrr);

    UCSR0B = (1<<RXEN0)|(1<<TXEN0); //Habilita transmissor e o receptor.
    UCSR0B |= (1<<RXCIE0); //Habilita interrupção.

    UCSR0C = (1<<USBS0)|(3<<UCSZ00); //Ajusta o formato do frame: 8 bits de dados e 2 de parada.    
}

//Função para envio o frame
void USART_transmit(unsigned char data){
    while(!((UCSR0A)&(1<<UDRE0))); //Espera a limpeza do registrador.
    UDR0 = data; //Coloca o dado no registrador de envio.
}

void STRING_transmit(const char *s){
	while (*s){
		USART_transmit(*s++);
	}
}
