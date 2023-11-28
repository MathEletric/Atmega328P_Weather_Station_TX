#include<avr/io.h>
//PD2 ... PD7 + PB0
int out;
void MSB_display7(int num){
    switch(num){
        case 0:
            out = 0x7E;
            break;
        case 1:
            out = 0x30;
            break;
        case 2:
            out = 0x6D;
            break;
        case 3:
            out = 0x79;
            break;
        case 4:
            out = 0x33;
            break;
        case 5:
            out = 0x5B;
            break;
        case 6:
            out =0x5F;
            break;
        case 7:
            out =0x70;
            break;
        case 8:
            out =0x7F;
            break;
        case 9:
            out =0x7B;
            break;  
    }
    ṔO

    }

}