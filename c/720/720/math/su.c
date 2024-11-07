#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void playGame();
void displayMenu();
int main()
{
    int choice;
    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            playGame();
            break;
        case 2:
            printf("感谢游玩，再见！\n");
            break;
        default:
            printf("无效的选项，请重新选择。\n");
        }
    } while (choice != 2);

    return 0;
}
void playGame()
{
    int secretNumber, guess, numTries = 0;
    srand((unsigned int)time(NULL)); // 使用时间戳作为随机数种子
    // 生成一个1到100之间的随机整数
    secretNumber = rand() % 100 + 1;

    printf("欢迎来到猜数字游戏！\n");
    printf("我已经想好了一个1到100之间的数字，你有10次机会来猜它。\n");

    do
    {
        printf("请输入你的猜测：");
        scanf("%d", &guess);
        numTries++;

        if (guess > secretNumber)
        {
            printf("太大了！再试一次。\n");
        }
        else if (guess < secretNumber)
        {
            printf("太小了！再试一次。\n");
        }
    } while (guess != secretNumber && numTries < 10);

    if (guess == secretNumber)
    {
        printf("恭喜你，你猜对了！用了%d次尝试。\n", numTries);
    }
    else
    {
        printf("很遗憾，你没有猜对。正确的数字是%d。\n", secretNumber);
    }
}

void displayMenu()
{
    printf("\n猜数字游戏菜单：\n");
    printf("1. 开始游戏\n");
    printf("2. 退出游戏\n");
    printf("请选择你的选项：");
}