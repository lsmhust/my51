/*共阴极静态数码**/
#include <reg52.h>
//段选
#define duanxuan P0
//位选连接138译码器
sbit weixuan1 = P1 ^ 0;
sbit weixuan2 = P1 ^ 1;
sbit weixuan3 = P1 ^ 2;

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
void digDisplay(u8);

//code 将数据存放在ram当中
u8 code smgduan[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d,
                     0x7d, 0x07, 0x7f, 0x6f, 0x77,
                     0x7c, 0x39, 0x5e, 0x79, 0x71};

void main()
{

    u8 count = sizeof(smgduan) / sizeof(u8);
    while (1)
    {
        u8 i;
        for (i = 0; i < count; i++)
        {
            digDisplay(i);
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

void digDisplay(u8 num)
{
    u8 i;
    for (i = 0; i < 8; i++)
    {
        switch (i)
        {
        case 0:
            //点亮第一个数码管
            weixuan1 = 0;
            weixuan2 = 0;
            weixuan3 = 0;
            break;
        case 1:
            //点亮第二个数码管
            weixuan1 = 1;
            weixuan2 = 0;
            weixuan3 = 0;
            break;
        case 2:

            weixuan1 = 0;
            weixuan2 = 1;
            weixuan3 = 0;
            break;
        case 3:

            weixuan1 = 1;
            weixuan2 = 1;
            weixuan3 = 0;
            break;
        case 4:

            weixuan1 = 0;
            weixuan2 = 0;
            weixuan3 = 1;
            break;
        case 5:

            weixuan1 = 1;
            weixuan2 = 0;
            weixuan3 = 1;
            break;
        case 6:

            weixuan1 = 0;
            weixuan2 = 1;
            weixuan3 = 1;
            break;
        case 7:

            weixuan1 = 1;
            weixuan2 = 1;
            weixuan3 = 1;
            break;

        default:
            break;
        }
        duanxuan = smgduan[num];
        delay(100);                                                                     
        duanxuan = 0x00;
    }
}