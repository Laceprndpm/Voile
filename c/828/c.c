// #include <stdio.h>
// int loop(int n)
// {
//     int m; // m 的作用域
//     scanf("%d", &m);
//     {
//         int i; // m 和 i 的作用域
//         for (i = m; i < n; i++)
//             puts("i is local to a sub-block\n");
//     }

//     return m; // m 的作用域，i 已经消失
// }
// #include <stdio.h>
// int main()
// {
//     loop(2);
// }
// hiding.c -- 块中的变量

// #include <stdio.h>
// int main()
// {
//     int x = 30;
//     // 原始的 x
//     printf("x  in  outer  block:  %d  at  %p\n", x, &x);
//     {
//         int x = 77;
//         // 新的 x，隐藏了原始的 x
//         printf("x  in  inner  block:  %d  at  %p\n", x, &x);
//     }
//     printf("x  in  outer  block:  %d  at  %p\n", x, &x);
//     while (x++ < 33)
//     // 原始的 x
//     {
//         static int x = 100;
//         // 新的 x，隐藏了原始的 x
//         x++;
//         printf("x  in  while  loop:  %d  at  %p\n", x, &x);
//     }
//     printf("x  in  outer  block:  %d  at  %p\n", x, &x);
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     int x = 0;
//     while (x < 5)
//     {
//         x++;
//         test();
//     }
// }
// void test()
// {
//     static int n = 1;
//     int m = 1;
//     printf("m=%d,n=%d", ++m, n++);
// }
// int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab = 1;
// #include <stdio.h>
// int main()
// {
//     printf("%d", aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab);
// }
// extern int test();
// int main()
// {
//     test();
// }
// #include <stdio.h>
// #include <time.h>
// #include<stdlib.h>
// int main()
// {
//     // 获取当前时间
//     time_t currentTime;
//     time(&currentTime);

//     // 将time_t格式的时间转换为本地时间
//     struct tm *localTime = localtime(&currentTime);

//     // 打印当前时间
//     printf("LocalTime: %d-%02d-%02d %02d:%02d:%02d\n",
//            localTime->tm_year + 1900, // tm_year字段从1900年开始计数
//            localTime->tm_mon + 1,     // tm_mon字段从0开始计数
//            localTime->tm_mday,
//            localTime->tm_hour,
//            localTime->tm_min,
//            localTime->tm_sec);
//     system("pause");
// }

// //     return 0;
// // }
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char *ptd;
//     ptd = malloc(30 * sizeof(char));
//     sprintf(ptd, "hello world!");
//     puts(ptd);
//     free(ptd);
//     printf("test");
//     system("pause");
// }
#include <stdlib.h>
#include <stdio.h>
// int main()
// {
//     int n;
//     printf("memory leak test\nenter the large of memory you want to leak\n");
//     scanf("%d", &n); // 需要泄露的次数，每次1MB
//     for (int i = 0; i < n; i++)
//     {
//         int *temp;
//         temp = malloc(1024 * 1024 * sizeof(char));
//     }
//     printf("done!\n");
//     system("pause");
// }
// #include <stdlib.h>
// #include <stdio.h>
// #include <time.h>
// int main()
// {
//     int n, m;
//     void *ptr;
//     printf("memory leak test\nenter the number of memory blocks you want to allocate\n");
//     scanf("%d", &n);
//     m = (1024 * 1024 * n) / sizeof(time_t);
//     for (int i = 0; i < m; i++)
//     {
//         ptr = (time_t *)malloc(1 * sizeof(time_t));
//         if (ptr == NULL)
//         {
//             fprintf(stderr, "Memory allocation failed on iteration %d\n", i);
//             exit(EXIT_FAILURE);
//         }
//         *(time_t *)ptr = time(0);
//         // 如果不需要使用这块内存，应该立即释放它以避免内存泄露
//         // free(ptr);
//     }

//     printf("done!\n");
//     system("pause");
//     return 0;
// }
int main()
{
    int n;
    int ar[10];
    int *restrict restar = (int *)malloc(10 * sizeof(int));
    int *par = ar;
    for (n = 0; n < 10; n++)
    {
        par[n] += 5;
        restar[n] += 5;
        ar[n] *= 2;
        par[n] += 3;
        restar[n] += 3;
    }
}
