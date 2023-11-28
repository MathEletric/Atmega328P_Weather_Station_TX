#include<avr/io.h>
void pinConfig(){
    //BOTÃO

    //FS1000
    DDRD &= ~(1<<1);
    PORTD |= (1<<1);

    //DISPLAY7SEG MAIS SIGNIFICATIVOS
    DDRD = DDRD | ((1<<2)+(1<<3)+(1<<4)+(1<<5)+(1<<6)+(1<<7));
    DDRB |= (1<<0);

    PORTD = PORTD | ((1<<2)+(1<<3)+(1<<4)+(1<<5)+(1<<6)+(1<<7));
    PORTB |= (1<<0);
    //DISPLAY7SEG MENOS SIGNIFICATIVOS
    DDRB = DDRB | ((1<<1)+(1<<2)+(1<<3)+(1<<4)+(1<<5));
    DDRC = DDRC | ((1<<4)+(1<<5));

    PORTB = PORTB | ((1<<1)+(1<<2)+(1<<3)+(1<<4)+(1<<5));
    PORTC = POTRC | ((1<<4)+(1<<5));

}