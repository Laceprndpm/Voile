// int sum(int ar[], int n) // 更通用的方法
// {
//     int i;
//     int total = 0;
//     for (i = 0; i < n; i++)
//         // 使用 n 个元素
//         total += *(ar + i);
//     // ar[i] 和 *(ar + i) 相同
//     return total;
// }
// #include <stdio.h>
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 6};
//     printf("%d", sum(&arr, 6));//为什么没有出现问题？答：暗盒
// }
// int count(char *ar, char *br)
// {
//     int count = 0;
//     while (1)
//     {

//         br -= 1;
//         count++;
//         if (ar == br)
//         {
//             return count;
//         }
//     }
// }
// #include <stdio.h>
// int main()
// {
//     int num = 0;
//     int arr[] = {1, 2, 3};
//     num = count(arr, &arr + 1);
//     printf("%d", num);
// }
#include <stdio.h>
int main()
{
    double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};

    const double locked[4] = {0.08, 0.075, 0.0725, 0.07};

    double *pnc = rates;
    // 有效

    pnc = locked;
    // 无效

    pnc = &rates[3];
    // 有效
}