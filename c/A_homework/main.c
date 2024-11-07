// #include <stdio.h>
// int findj(const int tg, const int *arr, const int j)
// {
//     int sign = 0, i;
//     for (i = 0; i < j; i++)
//     {
//         if (arr[i] == tg)
//         {
//             sign = 1;
//             break;
//         }
//     }
//     return sign;
// }
// int main()
// {
//     int arr[10] = {0};
//     int tmp;
//     int i, j;
//     for (i = 0, j = 0; i < 10; i++)
//     {
//         scanf("%d", &tmp);
//         if (findj(tmp, arr, j))
//         {
//             continue;
//         }
//         else
//         {
//             arr[j++] = tmp;
//         }
//     }
//     for (i = 0; i < j; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }
#include <stdio.h>
double calculate_term(int n)
{
    double numerator = 1;
    for (int i = 1; i <= n; i++)
        numerator *= i;
    double denominator = 1;
    for (int i = 1; i <= 2 * n + 1; i += 2)
        denominator *= i;
    return numerator / denominator;
}
double estimate_pi(int n)
{
    double sum = 1.0;
    for (int i = 1; i <= n; i++)
        sum += calculate_term(i);
    return 2 * sum;
}
int main()
{
    int n_terms = 50; // 指定要计算的项数，增加这个值可以得到更精确的n近似
    double pi_approximation = estimate_pi(50);
    printf("Estimate of Pi with %d terms:%.16lf\n", n_terms, pi_approximation);
    // double temp;
    // temp = 1 + 1.0 / 3 + 2.0 / (3 * 5) + (3.0 * 2) / (3 * 5 * 7);
    // printf("%lf", temp);
    return 0;
}