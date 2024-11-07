#include "game.h"
int IsFull(char board[ROW][COL], int row, int col);
void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
            board[i][j] = ' ';
    }
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        { // 打印数据
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
    printf("============================\n");
}
// void PlayerMove(char board[ROW][COL], int row, int col)
// {
//     int x = 0;
//     int y = 0;
//     int input_count = 0;
//     while (1)
//     {
//         printf("玩家走,输入坐标\n坐标:");
//         input_count = scanf("%d%d", &x, &y);
//         if (input_count != 2) // 检查是否成功读取两个整数
//         {
//             // 清除输入缓冲区中的剩余输入
//             while (getchar() != '\n')
//                 ;
//             printf("请输入2个数字\n");
//             goto*(&PlayerMove);
//         }
//         if (x >= 1 && x <= row && y >= 1 && y <= col)
//         {
//             if (board[x - 1][y - 1] == ' ') // caution
//             {
//                 board[x - 1][y - 1] = 'X';
//                 break;
//             }
//             else
//             {
//                 printf("非法的位置"); //
//             }
//         }
//         else
//         {
//             printf("非法的位置"); // 非法
//         }
//     }
// }
void PlayerMove(char board[ROW][COL], int row, int col)
{ // 根据实际的棋盘大小调整
    int x, y;
    int input_count;

    while (1)
    {
        printf("玩家走, 输入坐标\n坐标:");
        input_count = scanf("%d%d", &x, &y);

        // 清除输入缓冲区中的多余输入
        while (getchar() != '\n')
            ;

        if (input_count != 2)
        {
            printf("请输入2个数字\n");
            continue; // 重新输入
        }

        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = 'X';
                break;
            }
            else
            {
                printf("非法的位置\n"); // 位置已被占用
            }
        }
        else
        {
            printf("非法的位置\n"); // 坐标超出范围
        }
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    x = rand() % row;
    y = rand() % col;
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ')
        {
            board[x][y] = 'O';
            break;
        }
    }
}
char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') // ROW
        {
            return board[i][0];
        }
    }
    for (i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') // COL
        {
            return board[0][i];
        }
    }
    if (((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] & board[1][1] == board[2][0])) && board[1][1] != ' ')
    // 对角线
    {
        return board[1][1];
    }
    if (1 == IsFull(board, ROW, COL))
    {
        return 'Q';
    }
    return 'C';
}
int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}