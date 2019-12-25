#include <reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;


sbit led =P0^0;
void delay(u16);


void delay(u16 i){
    while (i--);
    
}


void main(){
    
    led = 0;
    while (1)
    {
        led =1;
        sleep(10000);
        led =0;
        sleep(10000);
    }
    
}