#include<stdio.h>
int Facl(int n)
{
    return((n>1)?Facl(n-1)*n:1);}