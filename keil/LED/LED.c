#include "Delay.h"
#include <REGX52.H>
#include "LED.H"

unsigned char LED_code[] =
    {
        0x3F, // 0
        0x06, // 1
        0x5B, // 2
        0x4F, // 3
        0x66, // 4
        0x6D, // 5
        0x7D, // 6
        0x07, // 7
        0x7F, // 8
        0x6F, // 9
        0x5C  // 10
};
void Nixie(unsigned char Location, unsigned char Number)
{
    switch (Location)
    {
    case 0:
        P2_4 = 1;
        P2_3 = 1;
        P2_2 = 1;
        break;
    case 1:
        P2_4 = 1;
        P2_3 = 1;
        P2_2 = 0;
        break;
    case 2:
        P2_4 = 1;
        P2_3 = 0;
        P2_2 = 1;
        break;
    case 3:
        P2_4 = 1;
        P2_3 = 0;
        P2_2 = 0;
        break;
    case 4:
        P2_4 = 0;
        P2_3 = 1;
        P2_2 = 1;
        break;
    case 5:
        P2_4 = 0;
        P2_3 = 1;
        P2_2 = 0;
        break;
    case 6:
        P2_4 = 0;
        P2_3 = 0;
        P2_2 = 1;
        break;
    case 7:
        P2_4 = 0;
        P2_3 = 0;
        P2_2 = 0;
        break;
    }
    if ((Number <= 9) & (Number >= 0))
        P0 = LED_code[Number];
    else
        P0 = LED_code[10];
}

void display_number(unsigned char position, unsigned int number, unsigned char length)
{
    unsigned char digit;
    unsigned char i;
    for (i = 0; i < length; i++)
    {
        digit = number % 10;
        Nixie(position + length - 1 - i, digit);
        number /= 10;
        Delay(2);
        P0 = 0x00;
    }
}