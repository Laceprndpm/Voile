#include <stdio.h>
#include <windows.h>
void loadings(int x);
int main()
{
    for (int i = 0; i < 11; i++)
    {
        loadings((int)i);
        Sleep(1000);
    }
}
void loadings(int x)
{
    int i;
    printf("loading:[..........]\b\b\b\b\b\b\b\b\b\b\b");
    for (i = 0; i < x; i++)
    {
        printf("#");
    }
    for (i = 0; i < x; i++)
    {
        printf("\b");
    }
    for (int i = 0; i < 9; i++)
    {
        printf("\b");
    }
}