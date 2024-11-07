#include <stdio.h>
int count = 0;
void h(int n, char from, char to, char temp)
{
    if (n == 1)
    {
        count++;
        printf("step%d\n移动盘1从%c到%c\n", count, from, to);
    }
    else
    {
        h(n - 1, from, temp, to);
        count++;
        printf("step%d\n移动盘%d从%c到%c\n", count, n, from, to);
        h(n - 1, temp, to, from);
    }
}
int main()
{
    int n;
    printf("一共几层:");
    scanf("%d", &n);
    h(n, 'A', 'C', 'B');
}