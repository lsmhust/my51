#include <reg52.h>
#include <INTRINS.H>



#define GPIO_LED P0

typedef unsigned char u8;
typedef unsigned int u16;

sbit IN_PL=P1^6;//数据置入、位移，低电平置入、高电平位移
sbit IN_DATA = P1^7;//串行输出
sbit CLK = P3^6;//时钟，上升沿有效，位移

void delay(u16);
u8 readDate();

u8 readDate()
{
    u8 indata;
    int i;
    IN_PL = 0;
    _nop_();
    IN_PL = 1;
    _nop_();

    indata = 0;

    for (i = 0; i < 8; i++)
    {
        indata = indata << 1;
        CLK = 0;
        _nop_();
        indata |= IN_DATA;
        CLK = 1;
    }
    return indata;
}

void delay(u16 i)
{
    while (i--)
        ;
}

void main()
{
    u8 value = 0;
    GPIO_LED = 0;
    while (1)
    {
        value = readDate();
        if (value != 0xff)
        {
            GPIO_LED = ~value;
        }
    }
}