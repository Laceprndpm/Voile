// cypher1.c -- 更改输入，空格不变

#include <stdio.h>
#define SPACE ' '
int main(void)
{
    char ch;
    ch = getchar();
    while (ch != '\n') // 当一行未结束时
    {

        if (ch == SPACE)
            putchar(ch);
        else
            putchar(ch + 1);
        ch = getchar();
    }
    putchar(ch);
    return 0;
}