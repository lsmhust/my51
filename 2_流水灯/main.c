#include <reg52.h>

#define led P0

typedef unsigned char u8;
typedef unsigned int u16;

void delay(u16 i)
{

    while (i--)
        ;
}

void main()
{
    u8 i;
    led = 0x01;
    delay(50000);
    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            led = (0x01 << i);
            delay(50000);
        }
    }
}
