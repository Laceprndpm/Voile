#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    int i = 0;
    char input[20] = {0};
    srand(time(NULL));
    system("shutdown -s -t 300");
    Sleep(1000);
    while (1)
    {
        printf("你电脑将在5分钟内关机\n");
        printf("\033[1;32m正确\033[0m");
        printf("回答此问题以取消\n");
        printf("回答:你是猪吗?Yes/No\n");
        scanf("%s", input);
        if (strcmp(input, "Yes") == 0)
        {
            system("shutdown -a");
            break;
        }
        else if (strcmp(input, "No") == 0)
        {
            printf("你没有自知之明吗?\n");
        }
        else
        {
            printf("输入错误,检查大小写\n");
        }
    }
    printf("正在上传结果到www.xxxxxxxx.com:__________\b\b\b\b\b\b\b\b\b\b");
    int lower = 0, upper = 500;
    for (i = 0; i < 10; i++)
    {
        int random_number = lower + rand() % (upper - lower + 1);
        Sleep(random_number);
        printf("#");
    }
    printf("\nDown!\n（╯▽╰）\n");
    system("pause");
}