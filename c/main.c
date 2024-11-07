// #include <stdio.h>
// int main()
// {
//     int T, n;
//     int i, j;
//     scanf("%d", &T);
//     for ( i = 0; i < T; i++)
//     {
//         scanf("%d",&n);
//         for ( i = n; i < 10; i++)
//         {

//         }

//     }

// }
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int T;
//     double *arr1;
//     double *arr2;
//     double X;
//     int i;
//     scanf("%d", &T);
//     arr1 = (double *)malloc(T * sizeof(double));
//     arr2 = (double *)malloc(T * sizeof(double));
//     for (i = 0; i < T; i++)
//     {
//         scanf("%lf", arr1 + i);
//     }
//     for (i = 0; i < T; i++)
//     {
//         scanf("%lf", arr2 + i);
//     }
//     X = 0;
//     for (i = 0; i < T; i++)
//     {
//         X += arr1[i] * arr2[i];
//     }
//     printf("%lf", X);

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int n;
//     int i, j;
//     int *price;
//     int money;
//     double max = 0;
//     scanf("%d", &n);
//     price = (int *)malloc(n * sizeof(int));
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", price + i);
//     }

//     for (i = 0; i < n; i++) //
//     {
//         for (j = 0; j < i; j++)
//         {
//             money = price[i] - price[j];
//             if (max < money / (i - j))
//             {
//                 max = money / (i - j);
//             }
//         }
//     }
//     printf("%lf", max);
// }
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int n, m;
//     int T;
//     int i;
//     int *pi;
//     scanf("%d", &T);
//     pi = (int *)malloc(T * sizeof(int));
//     for (i = 0; i < T; i++)
//     {
//         scanf("%d %d %*d %*d", &n, &m);
//         n > m ? n = m : 0;
//         pi[i] = ++n;
//     }
//     for (i = 0; i < T; i++)
//         printf("%d\n", pi[i]);
// }
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     unsigned long long int n, m;
//     unsigned long long int T;
//     unsigned long long int i;
//     unsigned long long int *pi;
//     scanf("%llu", &T);
//     pi = (unsigned long long int *)malloc(T * sizeof(unsigned long long int));
//     for (i = 0; i < T; i++)
//     {
//         scanf("%llu %llu %*llu %*llu", &n, &m);
//         n > m ? n = m : 0;
//         pi[i] = ++n;
//     }
//     for (i = 0; i < T; i++)
//         printf("%llu\n", pi[i]);
//     free(pi);
// }
//

// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// int n;
// int h_function(int base, int i)
// {
//     return (int)(pow(base, i)) % n;
// }

// int main()
// {
//     int k, m, q;
//     int i, j;
//     int input;
//     int sign;
//     char *pi;
//     char *pa;
//     scanf("%d%d%d%d", &n, &k, &m, &q);
//     pi = (char *)calloc(n, sizeof(char));
//     pa = (char *)calloc(q, sizeof(char));
//     for (i = 0; i < m; i++)
//     {
//         scanf("%d", &input);
//         for (j = 0; j < k; j++)
//         {
//             pi[h_function(input, k)] = 1;
//         }
//     }
//     for (i = 0; i < q; i++)
//     {
//         scanf("%d", &input);
//         sign = 1;
//         for (j = 0; j < k; j++)
//         {
//             if (!pi[h_function(input, j)])
//             {
//                 sign = 0;
//                 break;
//             }
//         }
//         if (sign)
//         {
//             pa[i] = 1;
//         }
//     }
//     for (i = 0; i < q; i++)
//     {
//         printf("%d ", pa[i]);
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>
// int n;
// int mypow(int base, int i)
// {
//     int b = 1;
//     while (i--)
//     {
//         b *= base;
//         b %= n;
//     }
//     return b;
// }

// int h_function(int base, int i)
// {
//     return ((mypow(base, i)) % n);
// }

// int main()
// {
//     int k, m, q;
//     int i, j;
//     int input;
//     int sign;
//     char *pi;
//     char *pa;
//     scanf("%d%d%d%d", &n, &k, &m, &q);
//     pi = (char *)calloc(n, sizeof(char));
//     pa = (char *)calloc(q, sizeof(char));
//     for (i = 0; i < m; i++)
//     {
//         scanf("%d", &input);
//         for (j = 0; j < k; j++)
//         {
//             pi[h_function(input, k)] = 1;
//         }
//     }

//     for (i = 0; i < q; i++)
//     {
//         scanf("%d", &input);
//         sign = 1;
//         for (j = 0; j < k; j++)
//         {
//             if (!pi[h_function(input, j)])
//             {
//                 sign = 0;
//                 break;
//             }
//         }
//         if (sign)
//         {
//             pa[i] = 1;
//         }
//     }
//     for (i = 0; i < q; i++)
//     {
//         printf("%d ", pa[i]);
//     }
//     free(pa);
//     free(pi);
//     return 0;
// }
// #include <stdio.h>
// // int main()
// // {
// //     int n;
// //     scanf("%d", &n);
// //     if (0 == n % 3)
// //     {
// //         printf("1 %d\n", n / 3);
// //     }
// //     else
// //     {
// //         printf("0 %d\n", (n % 3 + n / 3));
// //     }
// //     return 0;
// // }
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct
// {
//     int place;
//     int l;
//     int r;
// } Person;

// int compare(const void *a, const void *b)
// {
//     if (((Person *)a)->l - ((Person *)b)->l != 0)
//         return ((Person *)a)->l - ((Person *)b)->l;
//     else
//         return ((Person *)a)->r - ((Person *)b)->r;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     Person *people = (Person *)malloc(n * sizeof(Person));

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d %d", &people[i].l, &people[i].r);
//         people[i].place = i;
//     }

//     // 按 r 排序
//     qsort(people, n, sizeof(Person), compare);

//     int currentCount = 0;      // 当前加入人数
//     int totalParticipants = 0; // 总参与人数

//     for (int i = 0; i < n; i++)
//     {
//         // 检查当前人数是否在该人愿意加入的区间内
//         if (currentCount >= people[i].l && currentCount <= people[i].r)
//         {
//             totalParticipants++;
//             currentCount++;
//         }
//         else
//         {
//             people[i].place = -1;
//         }
//     }

//     printf("%d\n", totalParticipants);
//     for (int i = 0; i < n; i++)
//     {
//         if (people[i].place != -1)
//         {
//             printf("%d ", people[i].place + 1);
//         }
//     }

//     free(people);
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     int g;
//     scanf("%f", &g);
//     printf("");
// }
// #include <stdio.h>
// int main()
// {
//     // int value1 = 5;
//     // int value2 = 10;
//     // int *p = &value1;
//     // int *const *ptr = &p; // ptr 指向一个常量指针 p
// }
// #include <stdio.h>
// int main()
// {
//     int N;
//     int n, i, j;
//     scanf("%d", &N);
//     for (j = 0; j < N; j++)
//     {
//         int isprime = 1;
//         scanf("%d", &n);
//         for (i = 2; i < n; i++)
//         {
//             if (0 == n % i)
//             {
//                 isprime = 0;
//             }
//         }
//         if (isprime == 1)
//         {
//             printf("Yes\n");
//         }
//         else
//         {
//             printf("No\n");
//         }
//     }
// }
// #include <stdio.h>
// int main()
// {
//     printf("hello world");
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     int t;
//     double height;
//     char gender;
//     scanf("%d", &t);
//     for (int i = 0; i < t; i++)
//     {
//         while (getchar() != '\n')
//             ;
//         scanf("%c %lf", &gender, &height);
//         if (gender == 'M')
//         {
//             printf("%.2lf\n", height / 1.9);
//         }
//         else
//         {
//             printf("%.2f\n", height * 1.9);
//         }
//     }
//     return 0;
// }
// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     double a, b, x1 = 0, x2 = 0;
//     scanf("%lf%lf", &a, &b);
//     if (a >= 0)
//     {
//         while (fabs(x2 - x1) < b)
//         {
//             x1 = a / 4.0;
//             x2 = (1 / 2.0) * (x1 + a / x1);
//             x2 = x1;
//         }
//         printf("%.3f", x2);
//     }
//     else
//         printf("error");
//     return 0;
// }

// #include <stdio.h>
// void fun(int n)
// {
//     int i;
//     printf("%d=", n);
//     for (i = 2; i <= n; i++)
//         while (n != 1)
//         {
//             if (n % i == 0)
//             {
//                 printf("%d*", i);
//                 n = n / i;
//             }
//             else
//                 break;
//         }
//     printf("%d", n);
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     fun(n);
//     return 0;
// }

// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     double a, b, x1 = 0, x0 = 0;
//     scanf("%lf%lf", &a, &b);
//     if (a >= 0)
//     {
//         x1 = a / 4.0;
//         do
//         {
//             x0 = x1;
//             x1 = (1 / 2.0) * (x0 + a / x0);
//         } while (fabs(x0 - x1) > b);
//         printf("%.3f", x1);
//     }
//     else
//         printf("error");
//     return 0;
// }

// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     double a, b, x1 = 0, x0 = 0;
//     scanf("%lf%lf", &a, &b);
//     if (a >= 0)
//     {
//         x0 = a / 4.0;
//         while (fabs(x0 - x1) > b)
//         {

//             x1 = x0;
//             x0 = (1 / 2.0) * (x1 + a / x1);
//         }

//         printf("%.3f", x0);
//     }
//     else
//         printf("error");
//     return 0;
// }

// int atoi(char str[])
// {
//     int value = 0, i = 0;
//     while (str[i] != '\0')
//     {
//         value = value * 10 + str[i] - '0';
//         i++;
//     }
//     return value;
// }

// int main()
// {
//     char str[] = "123";
//     printf("%d", atoi(str));
//     return 0;
// }

// #include <stdio.h>
// void main(void)
// {
//     float Num[10] = {12, 22, 33, 36, 48, 56, 68, 72, 81}, New;
//     int i = 9;
//     scanf("%f", &New);
//     Num[i] = New;
//     while (i > 0 && Num[i] < Num[i - 1])
//     {
//         New = Num[i - 1];
//         Num[i - 1] = Num[i];
//         Num[i] = New;
//         i--;
//     }
//     for (i = 0; i < 10; i++)
//     {
//         printf("%.1f ", Num[i]);
//     }
// }

// #include<string.h>

// #include <stdio.h>
// void ss(char *s, char t)
// {
//     while (*s)
//     {
//         if (*s == t)
//             *s = t - 'a' + 'A';
//         s++;
//     }
// }
// void main(void)
// {
//     char str1[100] = "abcddfefdbd", c = 'd';
//     ss(str1, c);
//     printf("%s\n", str1);
// }

// #include <stdio.h>
// void sort(int a[], int n)
// {
//     int i, j, t;
//     for (i = 0; i < n - 1; i++)
//         for (j = i + 1; j < n; j++)
//             if (a[i] < a[j])
//             {
//                 t = a[i];
//                 a[i] = a[j];
//                 a[j] = t;
//             }
// }
// void main(void)
// {
//     int aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i;
//     sort(&aa[3], 5);
//     for (i = 0; i < 10; i++)
//         printf("%d,", aa[i]);
//     printf("\n");
// }

// #include <stdio.h>
// #include <string.h>
// void sort(char **str, int n)
// {
//     char *tmp;
//     int i, j;
//     for (i = 0; i < n - 1; i++)
//         for (j = 0; j < n - i - 1; j++)
//             if (strcmp(str[j], str[j + 1]) > 0)
//                 tmp = str[j], str[j] = str[j + 1], str[j + 1] = tmp;
// }
// void main(void)
// {
//     char **ps, *str[3] = {"BOOK",
//                           "COMPUTER",
//                           "CHINA"};
//     int i;
//     ps = str;
//     sort(ps, 3);
//     for (i = 0; i < 3; i++)
//         printf("%d %s ", i + 1, str[i]);
// }

// #include <stdio.h>

// // 判断是否为素数的函数
// int isprime(int i) {
//     if (i <= 1) return 0; // 1 及以下的数不是素数
//     for (int j = 2; j * j <= i; j++) {
//         if (i % j == 0) return 0; // 如果能被 j 整除，则不是素数
//     }
//     return i; // 是素数，返回该数
// }

// int main() {
//     int n, sum = 0;
//     printf("请输入一个正整数 n: ");
//     scanf("%d", &n);

//     for (int i = 1; i <= n; i++) {
//         sum += isprime(i); // 调用 prime 函数并累加素数
//     }

//     printf("1 到 %d 之间所有素数的和是: %d\n", n, sum);
//     return 0;
// }

// 选择排序函数
// /**
//  * @param num 待排序的数组
//  * @param n 数组的长度
//  * @return void
//  * @attention 时间复杂度为 O(n^2)
//  * @deprecated 选择排序
//  */
// void sort(short *num, int n) {
//     int i, j, min_idx;
//     short temp;
//     for (i = 0; i < n - 1; i++) {
//         min_idx = i;
//         for (j = i + 1; j < n; j++) {
//             if (num[j] < num[min_idx]) {
//                 min_idx = j;
//             }
//         }
//         // 交换最小元素和第 i 个元素
//         temp = num[min_idx];
//         num[min_idx] = num[i];
//         num[i] = temp;
//     }
// }

// int main() {
//     int n;
//     printf("请输入要排序的数的个数: ");
//     scanf("%d", &n);

//     short num[n];
//     printf("请输入 %d 个数:\n", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%hd", &num[i]);
//     }

//     sort(num, n);

//     printf("排序后的数是:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%hd ", num[i]);
//     }
//     printf("\n");

//     return 0;
// }

// 判断是否是完数的函数
short judge(int num)
{
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return sum == num;
}

int main()
{
    printf("1000以内的完数有:\n");
    for (int i = 1; i <= 1000; i++)
    {
        if (judge(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}