#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#include <stdio.h>

int BETA = 3950; // Parâmetro B do NTC

int main(void){
	initADC();
	Inicia_USART(9600);
	sei();
	
	char buffer[50];
	char temp[50];

	while (1){
		int AD0 = readADC(0);
	

		//int V0_mV = (int)((float)AD0 * 5000.0 / 1024.0); // Tensão em milivolts
	

		//Envia a tensão da porta A0
		snprintf(buffer, sizeof(buffer), "Tensao A0: %d.%02d V\n", V0_mV / 1000, V0_mV % 1000);
		enviar_string(buffer);

		//Calculo da temperatura
		float T = 1 / (log(1 / (1023.0 / AD0 - 1)) / BETA + 1.0 / 298.15) - 273.15;
		int T_dec = (int)(T * 100); // Temperatura multiplicada por 100

		//Envia a temperatura

		snprintf(temp, sizeof(temp), "T: %d.%02d graus C\n\n", T_dec / 100, T_dec % 100);
		enviar_string(temp);
    
		_delay_ms(3000);
	}

	return 0;
}