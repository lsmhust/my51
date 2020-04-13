#include <reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P0 ^ 0;
sbit key = P0 ^ 1;
void delay(u16);

void delay(u16 i)
{
    while (i--)
        ;
}

void main()
{

    led = 0;
    while (1)
    {
        if (key == 0)
        {
            delay(1000); //消抖
            if (key == 0)
            {
                led = ~led;
            }
            while (!key)
                ;
        }
    }
}