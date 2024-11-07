// // // #include <stdio.h>
// // // #include <unistd.h>
// // // #include <stdlib.h>

// // // int main()
// // // {
// // //     const int frames = 4;     // 旋转动画的帧数，必须是常量
// // //     const int delay = 200000; // 延迟时间（微秒）

// // //     // 定义旋转字符数组
// // //     const char *spinners[] = {
// // //         "-",
// // //         "/",
// // //         "|",
// // //         "\\"};

// // //     // 计算数组的长度
// // //     int num_spinners = sizeof(spinners) / sizeof(spinners[0]);

// // //     while (1)
// // //     { // 创建一个无限循环的动画
// // //         for (int i = 0; i < num_spinners; i++)
// // //         {
// // //             // 清屏
// // //             system("cls");

// // //             // 打印旋转字符
// // //             printf("%s\r", spinners[i]);

// // //             // 刷新输出缓冲区
// // //             fflush(stdout);

// // //             // 等待一段时间
// // //             usleep(delay);
// // //         }
// // //     }

// // //     return 0; // 程序不会执行到这里，因为动画是无限循环的
// // // }
// // // // #include<stdio.h>
// // // // int main()
// // // // {
// // // //     printf("hello");
// // // // }
// // #include <REGX52.H>
// // int xms;
// // void Delay(int xms);
// // void extil0_int(void)
// // {
// //     IT0 = 0;
// //     EX0 = 1;
// //     EA = 1;
// // }
// // void main()
// // {
// //     int i;
// //     unsigned char Time, t;
// //     for (i = 1; i < 4; i++)
// //     {
// //         P2 = 0xFE;
// //         Delay(20);
// //         P2 = 0xFD;
// //         Delay(20);
// //         P2 = 0xFB;
// //         Delay(20);
// //         P2 = 0xF7;
// //         Delay(20);
// //         P2 = 0xEF;
// //         Delay(20);
// //         P2 = 0xDF;
// //         Delay(20);
// //         P2 = 0xBF;
// //         Delay(20);
// //         P2 = 0x7F;
// //         Delay(20);
// //         P2 = 0xBF;
// //         Delay(20);
// //         P2 = 0xDF;
// //         Delay(20);
// //         P2 = 0xEF;
// //         Delay(20);
// //         P2 = 0xF7;
// //         Delay(20);
// //         P2 = 0xFB;
// //         Delay(20);
// //         P2 = 0xFD;
// //         Delay(20);
// //         P2 = 0xFE;
// //         Delay(20);
// //     }
// //     while (1)
// //     {
// //         for (Time = 0; Time < 10; Time++)
// //         {
// //             for (t = 0; t < 20; t++)
// //             {
// //                 P2 = 0x00;
// //                 Delay(Time);
// //                 P2 = 0xFF;
// //                 Delay(10 - Time);
// //             }
// //         }
// //         for (Time = 10; Time > 0; Time--)
// //         {
// //             for (t = 0; t < 20; t++)
// //             {
// //                 P2 = 0x00;
// //                 Delay(Time);
// //                 P2 = 0xFF;
// //                 Delay(10 - Time);
// //             }
// //         }
// //     }
// // }
// // void extil0() interrupt 0
// // {

// //     if (P3_2 == 0)
// //     {
// //         Delay(20);
// //         while (P3_2 == 0)
// //             ;
// //         Delay(20);
// //         while (1)
// //         {
// //             unsigned char Time, t;
// //             for (Time = 0; Time < 15; Time++)
// //             {
// //                 for (t = 0; t < 10; t++)
// //                 {
// //                     P2 = 0x00;
// //                     Delay(Time);
// //                     P2 = 0xFF;
// //                     Delay(15 - Time);
// //                 }
// //             }
// //             for (Time = 15; Time > 0; Time--)
// //             {
// //                 for (t = 0; t < 10; t++)
// //                 {
// //                     P2 = 0x00;
// //                     Delay(Time);
// //                     P2 = 0xFF;
// //                     Delay(15 - Time);
// //                 }
// //             }
// //         }
// //     }
// // }

// // void Delay(int xms)
// // {
// //     unsigned char i, j;
// //     while (xms)
// //     {
// //         i = 2;
// //         j = 239;
// //         do
// //         {
// //             while (--j)
// //                 ;
// //         } while (--i);
// //         xms--;
// //     }
// // }
// // #include <REGX52.H>
// // void Delay(int xms);
// // void main()
// // {
// //     int i, n;
// //     P2 = 0x00;
// //     while (1)
// //         ;
// //     n = 0x01;

// //     for (i = 0; i < 8; i++)
// //     {
// //         P2 = ~n;
// //         n = n << 1;
// //         Delay(20);
// //     }
// // }
// // void Delay(xms)
// // {
// //     unsigned char i, j;
// //     while (xms)
// //         i = 2;
// //     j = 239;
// //     do
// //     {
// //         while (--j)
// //             ;
// //     } while (--i);
// //     xms--;
// // }
// // #include <stdio.h>
// // int main()
// // {
// //     unsigned int x = 1;      // 只需一个字节的值
// //     char *byte = (char *)&x; // 将其地址转换为字符指针
// //     if (byte[0] == 1)
// //     {
// //         printf("小端字节序 (Little Endian)\n");
// //     }
// //     else
// //     {
// //         printf("大端字节序 (Big Endian)\n");
// //     }
// //     return 0;
// // }
// #include <REGX52.H>
// int xms;
// void Delay(int xms);
// void extil0_int(void)
// {
//     IT0 = 0;
//     EX0 = 1;
//     EA = 1;
// }
// void extil1_int(void)
// {
//     IT1 = 0;
//     EX0 = 1;
//     EA = 1;
// }
// unsigned char Time, t;
// // Á÷Ë®µÆµÄ³ÌÐò
// void main()
// {
//     int i;
//     for (i = 1; i < 4; i++)
//     {
//         P2 = 0xFE;
//         Delay(20);
//         P2 = 0xFD;
//         Delay(20);
//         P2 = 0xFB;
//         Delay(20);
//         P2 = 0xF7;
//         Delay(20);
//         P2 = 0xEF;
//         Delay(20);
//         P2 = 0xDF;
//         Delay(20);
//         P2 = 0xBF;
//         Delay(20);
//         P2 = 0x7F;
//         Delay(20);
//         P2 = 0xBF;
//         Delay(20);
//         P2 = 0xDF;
//         Delay(20);
//         P2 = 0xEF;
//         Delay(20);
//         P2 = 0xF7;
//         Delay(20);
//         P2 = 0xFB;
//         Delay(20);
//         P2 = 0xFD;
//         Delay(20);
//         P2 = 0xFE;
//         Delay(20);
//     }
//     // ¿ªÊ¼µ½ºôÎüµÆµÄ³ÌÐò
//     while (1)
//     {
//         extil0_int(); // Íâ²¿ÖÐ¶Ï0
//         extil1_int(); // Íâ²¿ÖÐ¶Ï1
//         for (Time = 0; Time < 5; Time++)
//         {
//             for (t = 0; t < 50; t++)
//             {
//                 P2 = 0x00;
//                 Delay(Time);
//                 P2 = 0xFF;
//                 Delay(5 - Time);
//             }
//         }
//         for (Time = 5; Time > 0; Time--)
//         {
//             for (t = 0; t < 50; t++)
//             {
//                 P2 = 0x00;
//                 Delay(Time);
//                 P2 = 0xFF;
//                 Delay(5 - Time);
//             }
//         }
//     }
// }
// // ÖÐ¶Ï²¿·Ö
// void extil0() interrupt 0
// {

//     if (P3_2 == 0)
//     {
//         Delay(20);
//         while (P3_2 == 0)
//             ;
//         Delay(20);
//         t -= 5; /*ÏëÍ¨¹ý°´¼ü¶ÔtµÄ¸Ä±äÊµÏÖ¶ÔºôÎüµÆ¼ä¸ôµÄ¿ØÖÆ*/
//     }
// }
// void extil1() interrupt 2
// {
//     if (P3_3 == 0)
//     {
//         Delay(20);
//         while (P3_3 == 0)
//             ;
//         Delay(20);
//         t += 5; /*ÏëÍ¨¹ý°´¼ü¶ÔtµÄ¸Ä±äÊµÏÖ¶ÔºôÎüµÆ¼ä¸ôµÄ¿ØÖÆ*/
//     }
// }

// void Delay(int xms)
// {
//     unsigned char i, j;
//     while (xms)
//     {
//         i = 2;
//         j = 239;
//         do
//         {
//             while (--j)
//                 ;
//         } while (--i);
//         xms--;
//     }
// }
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int place, Q;
//     int *pi;
//     int i;
//     int temp;
//     int sign;
//     scanf("%d", &place);
//     pi = (int *)malloc(place * sizeof(int));

//     for (i = 0; i < place; i++)
//     {
//         scanf("%d", (pi + i));
//     }
//     scanf("%d", &Q);
//     while (Q--)
//     {
//         sign = 1;
//         scanf("%d", &temp);
//         for (i = 0; i < place; i++)
//         {
//             if (temp == *(pi + i))
//             {
//                 printf("%d\n", i + 1);
//                 sign = 0;
//                 break;
//             }
//         }
//         if (sign)
//         {
//             printf("%d\n", 0);
//         }
//     }
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int num;
    int key;
} obj;

int compare(const obj *x, const obj *y)
{
    return x->num - y->num;
}

int bs(obj *p, int size, int target)
{
    int mid, left, right;
    right = size - 1;
    left = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if ((p[mid]).num == target)
        {
            return mid; // 找到目标，返回索引
        }
        if ((p[mid]).num < target)
        {
            left = mid + 1; // 目标在右侧
        }
        else
        {
            right = mid - 1; // 目标在左侧
        }
    }

    return -1; // 未找到目标
}

int main()
{

    int place, Q;
    obj *pi;
    int i;
    int temp;
    int sign;
    scanf("%d", &place);
    pi = (obj *)malloc(place * sizeof(obj));

    for (i = 0; i < place; i++)
    {
        scanf("%d", &((pi + i)->num));
        (pi + i)->key = i + 1;
    }
    qsort(pi, place, sizeof(obj), compare);
    scanf("%d", &Q);

    while (Q--)
    {
        scanf("%d", &temp);
        sign = bs(pi, place, temp);
        if (-1 != sign)
        {
            printf("%d\n", pi[sign].key);
        }
        else
        {
            printf("0\n");
        }
    }
}