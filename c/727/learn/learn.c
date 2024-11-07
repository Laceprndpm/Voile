#include<stdio.h>
int main()
{
    int a = 0;
    const int* p = &a;
    const int **pp = &p;
    printf("%d", a);
}
