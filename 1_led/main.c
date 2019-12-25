#include <reg52.h>

sbit led =P0^0;
void sleep(int);


void sleep(int n){
    while (n>0)
    {
        n-=1;
    }
    
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