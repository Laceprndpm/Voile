// P29数据的存储
#include <stdio.h>
// #include <assert.h>
// int check()
// {
//     int a = 1;
//     return *(char *)(&a);
// }
// int main()
// {
//     char *p;
//     p = "ab";
//     printf("%s", p);
// }
// 11111111 11111111 11111111 10000000
int main()
{
    char arr1[] = "abcdef";
    char arr2[] = "abcdef";
    char *p1 = "abcdef";
    char *p2 = "abcdef";
    if (arr1 == arr2)
    {
        printf("h\n");
    }
    else
    {
        printf("a\n");
    }
    if (p1 == p2)
    {
        printf("test\n");
    }
}