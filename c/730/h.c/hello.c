// #include<stdio.h>
// void hellof()
// {
//     printf("hello world");
// }
// int main()
// {
//     void (*p)() = &hellof;
//     (*(void (*)())p)();
// }
// #include <stdio.h>
// int add(int x, int y)
// {
//     return x + y;
// }
// int sub(int x, int y)
// {
//     return x - y;
// }
// int mul(int x, int y)
// {
//     return x * y;
// }
// int div(int x, int y)
// {
//     return x / y;
// }

// int main()
// {
//     int (*parr[4])(int, int) = {add, sub, mul, div};
//     int i = 0;
//     for (i = 0; i < 4; i ++)
//     {
//         printf("%d\n", ((*parr[i])(2, 3)));
//     }
// }
#include<stdio.h>
int main()
{
    int (*pfArr[4])(int);
    int (*(*ppfArr)[4])(int) = &pfArr;
    int (*(*ppfArr_Arr[4])[4])(int);
    int (*(*(*pppfArr_Arr)[4])[4])(int) = &ppfArr_Arr;
    ppfArr_Arr[0] = ppfArr;
}