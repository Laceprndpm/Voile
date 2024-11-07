#include<stdio.h>
int think(int n)
{
    return(n<=2?1:think(n-1)+think(n-2));
}
int main()
{
    int n = think(500000);
    printf("%d",n);
}