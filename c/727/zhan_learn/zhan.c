#include<stdio.h>
int main()
{
    int i = 0;
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (i = 0; i <= 11; i ++ )
    {
        printf("test");
        arr[i] = 0;
    }
}