#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
    int i=0;
    char arr1[]={'!','@','#','$','%','^'};
    while(1)
    {
        i++;
        printf("%c",arr1[i]);
        system("cls");
        if(5==i)
        {
            i=0;
        }
    }
}