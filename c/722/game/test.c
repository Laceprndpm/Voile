#include "game.h"
void menu()
{
    printf("1.play 0.exit\n");
}
void game()
{
    char ret;
    char board[ROW][COL];
    InitBoard(board, ROW, COL);    // 就初始化棋盘
    DisplayBoard(board, ROW, COL); // 显示棋盘
    while (1)
    {
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        // 玩家
        // 电脑
    }
    if (ret == 'X')
    {
        printf("你赢了！\n");
    }
    else if (ret == 'O')
    {
        printf("你输了！\n");
    }
    else
    {
        printf("平局！\n");
    }
}
void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("choose=");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("is 3\n");
            game();
            break;
        case 0:
            printf("exit");
            break;
        default:
            printf("input?");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}