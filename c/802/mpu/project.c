#include <REGX52.h>
void Delayxms(unsigned int x) //@11.0592MHz
{
    while (x--)
    {
            unsigned char i, j;

            i = 2;
            j = 199;
            do
            {
                while (--j)
                    ;
            } while (--i);
        
    }
}
int main()
{
    unsigned char led_pattern = 0x01;

    while (1)
    {
        P2 = ~led_pattern;
        Delayxms(1000);

        led_pattern <<= 1;

        if (led_pattern == 0)
        {
            led_pattern = 0x01;
        }
    }
}