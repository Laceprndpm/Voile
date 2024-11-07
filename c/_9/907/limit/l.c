// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <errno.h>
// #include <limits.h>
// int main()
// {
//     int *p = malloc(LONG_MAX);
//     if (p == NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         printf("success");
//     };
//     getchar();
// }
// #include <stdio.h>

// int main()
// {
//     int i;
//     int arr[10]; // 一个包含10个整数的数组
//     // 初始化数组
//     for (i = 0; i < 10; i++)
//     {
//         arr[i] = i;
//     }

//     // 故意越界访问，试图修改i的值
//     for (i = 0; i <= 11; i++)
//     {
//         arr[i] = i;
//         printf("i = %d\n", i);
//         if (i > 10)
//         {
//             printf("死循环发生\n");
//             break;
//         }
//     }

//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
int main()
{
    while (1)
    {
        malloc(1);
    }
    
}