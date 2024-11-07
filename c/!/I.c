#include<stdio.h>
int jc (int x)
{
    int i=x;
    int y=1;
    for(;i>=2;i--)
    y*=i;
    return y;
}
int main()
{
    int j=0;
    for (int i = 1;i<=10;i++)
    j+=jc(i);
    printf("%d",j);
}
// int jc(int x)
// {
//     int y=1;
//     for(;x>=2;x--)
//     y=y*x;
//     return y;
// }
// #include<stdio.h>

// int jc(int x)
// {
//     int y = 1;
//     for (int i = 1; i <= x; i++) // 使用一个额外的循环变量 i，从 1 乘到 x
//         y = y * i;
//     return y;
// }

// int main()
// {
//     int j = 0;
//     for (int i = 1; i <= 10; i++)
//         j = j + jc(i);
//     printf("%d\n", j); // 在结果后添加一个换行符，以便输出更清晰
//     return 0; // main 函数应该返回一个值，通常是 0 表示成功
// }
// #include <stdio.h>

// // 函数用于计算阶乘
// unsigned long long factorial(int n) {
//     unsigned long long result = 1;
//     for (int i = 2; i <= n; i++) {
//         result *= i;
//     }
//     return result;
// }

// int main() {
//     unsigned long long sum = 0; // 初始化阶乘和

//     // 计算从1的阶乘到10的阶乘的和
//     for (int i = 1; i <= 10; i++) {
//         sum += factorial(i);
//     }

//     // 打印结果
//     printf("The sum of factorials from 1! to 10! is: %llu\n", sum);

//     return 0;
// }