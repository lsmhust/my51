#include <reg52.h>
typedef unsigned int u16;
sbit buzz = P1^5;

void delay(u16 i)
{

    while (i--)
        ;
}

void main()
{
    
    while (1)
    {
        buzz=~buzz;
        delay(10);
    }
}
