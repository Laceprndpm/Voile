#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    printf("你电脑将在5分钟内关机\n");
    char input[20] = {0};
    system("shutdown -s -t 300");
    while (1)
    {
        printf("肯德基疯狂星期四V我50?\nYes/No\n");
        scanf("%s", input);
        if (strcmp(input, "我") == 0)
        {
            system("shutdown -a");
            break;
        }
        else
        {
            printf("输入错误\n");
        }
    }
}