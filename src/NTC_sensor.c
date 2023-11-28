#include<stdio.h>
#include<math.h>
int BETA = 3950; // Parâmetro B do NTC
char buffer[50];
char temp[50];
void NTC_sensor(){
    int ADC_measure = ADC_read();
    
    //Calculo da temperatura
    float T = 1 / (log(1 / (1023. / ADC_measure - 1)) / BETA + 1.0 / 298.15) - 273.15;
    int T_dec = (int)(T * 100); // Temperatura multiplicada por 100

    //Envia a temperatura
    snprintf(temp, sizeof(temp), "Temp: %d.%02d oC\n\n", T_dec / 100, T_dec % 100);
    STRING_transmit(temp);
}