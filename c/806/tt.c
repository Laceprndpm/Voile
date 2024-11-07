/* floatcnv.c -- 不匹配的浮点型转换 */

#include <stdio.h>

int main(void)

{
    int val1 = 1, val2 = 2, val3 = 3;
    printf("%-9d %-9d %-9d\n", val1, val2, val3);
    val1 = 10, val2 = 20, val3 = 30;
    printf("%-9d %-9d %-9d\n", val1, val2, val3);
    val1 = 100, val2 = 200, val3 = 300;
    printf("%-9d %-9d %-9d\n", val1, val2, val3);
}