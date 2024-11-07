// // #include <stdio.h>
// // float small(float num1, float num2)
// // {
// //     float min;

// //     min = num1;

// //     if (num2 < min)
// //         min = num2;

// //     return min;
// // }

// // void main(void)
// // {
// //     float i, j, n, min;

// //     printf("请输入三个小数：");
// //     scanf("%f,%f,%f", &i, &j, &n);

// //     min = small(i, j);
// //     min = small(n, min);

// //     printf("%f,%f,%f三个小数中最小的是：%f\n", i, j, n, min);
// // }
// // 查看c变量在new中的位置
// // struct new
// // {
// //     int a : 2;
// //     int : 0;
// //     int b : 3;
// //     char c;
// // };
// // #include <stdio.h>
// // int main()
// // {
// //     printf("%d", (int)(&(((struct new *)0)->c)));
// // }
// // #define MAX(a,b) ((a)>(b)?(a):(b))
// // #include <stdio.h>
// // int main()
// // {
// //     int a = 2;
// //     int b = 3;
// //     printf("%d", MAX(a, b));
// // }
// // #include<stdio.h>
// // int add(int a, int b);
// // int main()
// // {
// //     int a = 2;
// //     int b = 3;
// //     int af = 2.5;
// //     int c = add(af, b);
// //     printf("%d", c);
// // }
// // int add(int a,int b)
// // {
// //     return a + b;
// // }
// // #include<stdio.h>
// // int main()
// // {
// //     int a = 2;
// //     int i;
// //     int count;
// //     scanf("%d", &a);
// //     char arr[a];
// //     count = sizeof(arr);
// //     for ( i = 0; i < count; i++)
// //     {
// //         arr[i] = i;
// //         printf("%d", arr[i]);
// //     }
// // }
// // #include <stdio.h>
// // #include <string.h>

// // int romanToInt(char *s)
// // {
// //     int symbolValues[26] = {0}; // 初始化数组
// //     symbolValues['I' - 'A'] = 1;
// //     symbolValues['V' - 'A'] = 5;
// //     symbolValues['X' - 'A'] = 10;
// //     symbolValues['L' - 'A'] = 50;
// //     symbolValues['C' - 'A'] = 100;
// //     symbolValues['D' - 'A'] = 500;
// //     symbolValues['M' - 'A'] = 1000;

// //     int n = strlen(s);
// //     int value = 0;

// //     for (int i = 0; i < n; i++)
// //     {
// //         int n1 = symbolValues[s[i] - 'A'];
// //         int n2 = (i + 1 < n) ? symbolValues[s[i + 1] - 'A'] : 0;

// //         if (n1 >= n2)
// //         {
// //             value += n1;
// //         }
// //         else
// //         {
// //             value -= n1;
// //         }
// //     }

// //     return value;
// // }
// // // if (symbolValues[s[n - 2] - 'A'] >= symbolValues[s[n - 1] - 'A'])
// //     int main()
// //     {
// //         char roman[] = "IX"; // 示例输入
// //         printf("整数值: %d\n", romanToInt(roman));
// //         return 0;
// //     }
// #include <stdio.h>
// #include <string.h>

// int romanToInt(char *s)

// {
//     int symbolValues[26];
//     symbolValues['I' - 'A'] = 1;
//     symbolValues['V' - 'A'] = 5;
//     symbolValues['X' - 'A'] = 10;
//     symbolValues['L' - 'A'] = 50;
//     symbolValues['C' - 'A'] = 100;
//     symbolValues['D' - 'A'] = 500;
//     symbolValues['M' - 'A'] = 1000;

//     int n = strlen(s);
//     int value = 0;
//     for (int i = 0; i <= n - 1; i++)
//     {
//         int n1 = symbolValues[s[i] - 'A'];
//         int n2 = (i + 1 < n) ? symbolValues[s[i + 1] - 'A'] : 0;

//         if (i == n - 2)
//         {
//             break;
//         }
//         else if (n1 >= n2)
//         {
//             value += n1;
//         }
//         else
//         {
//             value -= n1;
//         }
//     }

//     // if (symbolValues[s[n - 2] - 'A'] >= symbolValues[s[n - 1] - 'A'])
//     if (symbolValues[s[n - 2] - 'A'] >= symbolValues[s[n - 1] - 'A'])
//     {
//         value += symbolValues[s[n - 2] - 'A'];
//         value += symbolValues[s[n - 1] - 'A'];
//     }
//     else
//     {
//         value -= symbolValues[s[n - 2] - 'A'];
//         value += symbolValues[s[n - 1] - 'A'];
//     }

//     return value;
// }

// int main()
// {
//     char roman[] = "MCMXCIV"; // 示例输入
//     printf("整数值: %d\n", romanToInt(roman));
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     char *suits[] = {"方块", "梅花", "爱心", "桃花"};
//     char ranks[] = {"A23456789TJQK"};
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 13; j++)
//         {
//             if (j != 9)
//             {
//                 printf("%s%c ", suits[i], ranks[j]);
//             }
//             else
//             {
//                 printf("%s10 ", suits[i]);
//             }
//         }
//         printf("\n");
//     }
//     getchar();
// }
// #include <stdio.h>
// #include <stddef.h>
// size_t Fuction(char *p)
// {
//     char *start = p;
//     char *end = p;
//     while (*end)
//     {
//         end++;
//     }
//     return end - start;
// }

// int main()
// {
//     char arr[] = "abcdef";
//     size_t len = Fuction(arr);
//     printf("%zd\n", len);
// }
// #include <stdio.h>
// #include <string.h>
// int a;
// int main()
// {
//     // char *p = "hh";
//     // typedef char *ptr_to_char;
//     // ptr_to_char a, b, c;
//     // char *d, e, f;
//     // b = "222";
//     // e = "222";
//     // printf("%s%s", b, e);
//     //     const char* const p;
//     //     p = NULL;

//     // printf("%d", a);
//     // switch (p)
//     // {
//     // case "hh":
//     //     printf("case");
//     // }
//     // char mat(void);
//     // int a = (int)mat();
//     // printf("%d", a);
// }

// // char mat(void)
// // {
// //     return (char)2;
// // }
void Delay1ms(int xms);
void main()
{
    int test = 0x01;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            P2 = ~test;
            test <<= 1;
            test %= 255;
            Delay1ms(20);
        }
        
    }
    // Your code
    while (1) // <---Add a while loop to 
        ;
}
void Delay1ms(int xms)
{
    unsigned char i, j;
    while (xms)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j)
                ;
        } while (--i);
        xms--;
    }
}