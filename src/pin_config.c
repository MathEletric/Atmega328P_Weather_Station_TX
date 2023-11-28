#include<avr/io.h>
void pinConfig(){
    //BOTÃO
    DDRD &= ~(1<<0);
    PORTD |= (1<<0);
    //FS1000


    //DISPLAY7SEG MAIS SIGNIFICATIVOS
    DDRD = DDRD | ((1<<2)+(1<<3)+(1<<4)+(1<<5)+(1<<6)+(1<<7));
    DDRB |= (1<<0);
    //DISPLAY7SEG MENOS SIGNIFICATIVOS
    DDRB = DDRB | ((1<<1)+(1<<2)+(1<<3)+(1<<4)+(1<<5));
    DDRC = DDRC | ((1<<4)+(1<<5));
}