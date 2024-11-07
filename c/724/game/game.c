#include <stdio.h>
void game()
{
}
void menu()
{
    printf("==============\n");
    printf("|1.开始 0.退出|\n");
    printf("==============\n");
}
void test()
{
    int input;
    do
    {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            break;
        default:
            printf("非法的输入\n");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}