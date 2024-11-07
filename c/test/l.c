// #include <stdio.h>
// char mat()
// {
//     char key = 0;
//     int temp = 0;
//     scanf("%d", &temp);
//     key = (char)temp;
//     return key;
// }
// int main()
// {
//     int passwd = 0;
//     int count = 0;
//     do
//     {
//         int test = 0;
//         passwd = 10 * passwd;
//         test = mat();
//         passwd = passwd + test;
//         count++;
//     } while (count < 4);
//     if (passwd == 1628)
//     {
//         printf("1");
//     }
//     else
//     {
//         printf("0");
//     }
// }
// int main()
// {
//     char count = 0;
//     unsigned int passwd;
//     Nixie(0, (passwd / 100000));
//     Delay(500);
//     Nixie(1, ((passwd % 100000) / 10000));
//     Delay(500);
//     Nixie(2, (passwd % 10000) / 1000);
//     Delay(500);
//     Nixie(3, (passwd % 1000) / 100);
//     Delay(500);
//     Nixie(4, (passwd % 100) / 10);
//     Delay(500);
//     Nixie(5, (passwd % 10));
//     Delay(500);
//     do
//     {
//         unsigned char test = 0;
//         passwd = 10 * passwd;
//         test = mat();
//         passwd = passwd + test;
//         Delay(200);
//         Nixie(0, test);
//         Delay(500);
//         Nixie(0, 0);
//         Delay(500);
//         Nixie(0, (passwd / 100000));
//         Delay(500);
//         Nixie(1, ((passwd % 100000) / 10000));
//         Delay(500);
//         Nixie(2, (passwd % 10000) / 1000);
//         Delay(500);
//         Nixie(3, (passwd % 1000) / 100);
//         Delay(500);
//         Nixie(4, (passwd % 100) / 10);
//         Delay(500);
//         Nixie(5, (passwd % 10));
//         Delay(500);
//         count++;
//     } while (count < 4);
//     Delay(1000);
//     if (passwd == 1628)
//     {
//         Nixie(1, 2);
//     }
//     else
//     {
//         Nixie(1, 9);
//     }
//     while (1)
//         ;
// }
// #include<stdio.h>
// int main()
// {
//     char a = 0;
//     int b = 1;
//     printf("%d", (b = a));
// }
#include <stdio.h>
float test = 123.456;
void pr(int* a)
{
    printf("%d", *a);
}
int main()
{
    pr(&test);
    return 0;
}