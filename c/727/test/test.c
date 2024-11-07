#include<string.h>
#include<stdio.h>
struct Book
{
    char name[20];
    short price;
};
int main()
{
    struct Book b1 = {"原神",55};
    strcpy(b1.name,"崩坏");
    printf("书名%s",b1.name);
}