#include <stdio.h>
#include <string.h>

int main()
{
    char name[20];
    char SB[20] = "YangZuoXiao";
    printf("name: ");
    scanf("%19s", name);  // %19s 防止缓冲区溢出

    if (strcmp(name, SB) == 0)
    {
        printf("我c你**!\n");
    }
    return 0;
}