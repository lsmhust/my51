/*共阳极静态数码**/
#include <reg52.h>

#define num P0

typedef unsigned char u8;
typedef unsigned int u16;

//共阴数码管表
/*
0、0x3f
1、0x06
2、0x5b
3、0x4f
4、0x66
5、0x6d
6、0x7d
7、0x07
8、0x7f
9、0x6f
A、0x77
B、0x7c
C、0x39
D、0x5e
E、0x79
F、0x71
无显示、0x00
*/
void delay(u16);

//code 将数据存放在ram当中
u8 smgduan[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,
                0x7d, 0x07, 0x7f, 0x6f, 0x77,
                0x7c, 0x39, 0x5e, 0x79, 0x71};

void main()
{
    u8 i;
    u8 count = sizeof(smgduan) / sizeof(u8);
    while (1)
    {
        for (i = 0; i < count; i++)
        {
            //开发共阳需要取反
            num = ~smgduan[i];
            delay(50000);
        }
    }
}

void delay(u16 i)
{
    while (i--)
    {
        /* code */
    }
}