// #include <stdio.h>
// #include <stdlib.h> // 提供 exit()的原型
// int main(int argc, char *argv[])
// {
//     int ch;// 读取文件时，储存每个字符的地方
//         FILE *fp; // “文件指针”
//         unsigned long count = 0;
//     if (argc != 2)
//     {
//         printf("Usage: %s filename\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }
//     if ((fp = fopen(argv[1], "r")) == NULL)
//     {
//         printf("Can't open %s\n", argv[1]);
//         exit(EXIT_FAILURE);
//     }
//     while ((ch = getc(fp)) != EOF)
//     {
//         putc(ch, stdout);// 与 putchar(ch); 相同
//             count++;
//     }
//     fclose(fp);
//     printf("File %s has %lu characters\n", argv[1], count);
//     return 0;
// }
// #include   <stdio.h>
// int main(int argc, char *argv[])
// {
//     int  count;
//     printf("The  command  line  has  %d  arguments:\n",  argc  -  1);
// for
//       (count  =  1;  count  <  argc;  count++)
//         printf("%d:  %s\n",  count,  argv[count]);
// printf("\n");
// return  0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// int main()
// {
//     srand(time(0));
//     int number = rand() % 100 + 1;
//     int count = 0;
//     int a = 0;
//     printf("我已经想好了一个1到100之间的数。");
//     do
//     {
//         printf("请猜猜这个1到100之间数。");
//         scanf("%d", &a);
//         count++;
//         if (a > number)
//         {
//             printf("你猜的数大了。");
//         }
//         else if (a < number)
//         {
//             printf("你猜的数小了。");
//         }
//     } while (a != number);
//     printf("太好了，你用了%d次就猜到了答案。\n", count);
//     return 0;
// }
// #include <wchar.h>
// #include <stdio.h>
// void post_user(struct person *ptr);
// int main()
// {
//     struct person
//     {
//         wchar_t name[20];
//         char username[20];
//         char password[20];
//         int arr[60];
//     };
//     struct person p = {
//         L"小明", // 使用宽字符字符串
//         "tttt",
//         "123456",
//         {1, 2, 3} // 直接初始化数组
//     };
//     struct person *pt = &p;
//     post_user(pt);
//     void postuser(struct person * ptr)
//     {
//         puts(ptr->username);
//         puts(ptr->password);
//     }
// }
// #include <wchar.h>
// #include <stdio.h>

// struct person
// {
//     wchar_t name[20];
//     char username[20];
//     char password[20];
//     int arr[60];
// };

// void test(const struct person *);

// int main()
// {
//     struct person p = {
//         L"小明", // 使用宽字符字符串
//         "tttt",
//         "123456",
//         {1, 2, 3} // 直接初始化数组
//     };
//     struct person *pt;
//     pt = &p;
//     test(pt);
// }

// void test(const struct person *ptr)
// {
//     puts(ptr->username);
//     puts(ptr->password);
// }
/* funds2.c -- 传递指向结构的指针 */

// #include <stdio.h>

// #define FUNDLEN 50

// struct funds
// {

//     char bank[FUNDLEN];

//     double bankfund;

//     char save[FUNDLEN];

//     double savefund;
// };

// double sum(const struct funds *); /* 参数是一个指针 */

// int main(void)

// {

//     struct funds stan = {

//         "Garlic-Melon Bank",

//         4032.27,

//         "Lucky's Savings and Loan",

//         8543.94

//     };

//     printf("Stan has a total of $%.2f.\n", sum(&stan));

//     return 0;
// }

// double sum(const struct funds *money)

// {

//     return (money->bankfund + money->savefund);
// }
// #define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
// #include <stdio.h>
// int main()
// {
//     struct box_props
//     {
//         _Bool opaque : 1;
//         unsigned int fill_color : 2;
//         unsigned int test: 4;
//         _Bool show_border : 1;
//         unsigned int border_color : 3;
//         unsigned int border_style : 2;
//         unsigned int : 2;
//     } test;

//     struct s
//     {
//         unsigned int field1 : 1;
//         unsigned int : 2;
//         unsigned int field2 : 1;
//         unsigned int : 0;
//         unsigned int field3 : 1;
//     } stuff;
//     printf("Size of struct: %zu bytes\n", sizeof(test));
// }
int P0;
int P2;
void Nixie(unsigned char Location, unsigned char Number)
{
    unsigned char code[10] = {
        0x3F, // 0
        0x06, // 1
        0x5B, // 2
        0x4F, // 3
        0x66, // 4
        0x6D, // 5
        0x7D, // 6
        0x07, // 7
        0x7F, // 8
        0x6F  // 9
    };
    unsigned char location[8] = {
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00100000,
        0b01000000,
        0b10000000};
    P0 = code[Number];
    P2 = location[Location];
}

int main()
{
    Nixie(0, 6);
    return 0;
}
/* dualview.c -- 位字段和按位运算符 */

// #include <stdio.h>
// #include <stdbool.h>
// #include <limits.h>

// /* 位字段符号常量 */

// /* 边框线样式 */
// #define SOLID 0
// #define DOTTED 1
// #define DASHED 2

// /* 三原色 */
// #define BLUE 4
// #define GREEN 2
// #define RED 1

// /* 混合颜色 */
// #define BLACK 0
// #define YELLOW (RED | GREEN)
// #define MAGENTA (RED | BLUE)
// #define CYAN (GREEN | BLUE)
// #define WHITE (RED | GREEN | BLUE)

// /* 按位方法中用到的符号常量 */
// #define OPAQUE 0x1
// #define FILL_BLUE 0x8
// #define FILL_GREEN 0x4
// #define FILL_RED 0x2
// #define FILL_MASK 0xE
// #define BORDER 0x100
// #define BORDER_BLUE 0x800
// #define BORDER_GREEN 0x400
// #define BORDER_RED 0x200
// #define BORDER_MASK 0xE00
// #define B_SOLID 0
// #define B_DOTTED 0x1000
// #define B_DASHED 0x2000
// #define STYLE_MASK 0x3000

// const char *colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

// struct box_props
// {
//     bool opaque : 1;
//     unsigned int fill_color : 3;
//     unsigned int : 4;
//     bool show_border : 1;
//     unsigned int border_color : 3;
//     unsigned int border_style : 2;
//     unsigned int : 2;
// };

// union Views /* 把数据看作结构或unsigned short类型的变量 */
// {
//     struct box_props st_view;
//     unsigned short us_view;
// };

// void show_settings(const struct box_props *pb);
// void show_settings1(unsigned short);
// char *itobs(int n, char *ps);

// int main(void)
// {
//     /* 创建Views联合，并初始化initialize struct box view */
//     union Views box = {{true, YELLOW, true, GREEN, DASHED}};
//     char bin_str[8 * sizeof(unsigned int) + 1];

//     printf("Original box settings:\n");
//     show_settings(&box.st_view);
//     printf("\nBox settings using unsigned int view:\n");
//     show_settings1(box.us_view);
//     printf("bits are %s\n", itobs(box.us_view, bin_str));

//     box.us_view &= ~FILL_MASK;               /* 把表示填充色的位清0 */
//     box.us_view |= (FILL_BLUE | FILL_GREEN); /* 重置填充色 */
//     box.us_view ^= OPAQUE;                   /* 切换是否透明的位 */
//     box.us_view |= BORDER_RED;               /* 错误的方法 */
//     box.us_view &= ~STYLE_MASK;              /* 把样式的位清0 */
//     box.us_view |= B_DOTTED;                 /* 把样式设置为点 */

//     printf("\nModified box settings:\n");
//     show_settings(&box.st_view);
//     printf("\nBox settings using unsigned int view:\n");
//     show_settings1(box.us_view);
//     printf("bits are %s\n", itobs(box.us_view, bin_str));

//     return 0;
// }

// void show_settings(const struct box_props *pb)
// {
//     printf("Box is %s.\n", pb->opaque == true ? "opaque" : "transparent");
//     printf("The fill color is %s.\n", colors[pb->fill_color]);
//     printf("Border %s.\n", pb->show_border == true ? "shown" : "not shown");
//     printf("The border color is %s.\n", colors[pb->border_color]);
//     printf("The border style is ");
//     switch (pb->border_style)
//     {
//     case SOLID:
//         printf("solid.\n");
//         break;
//     case DOTTED:
//         printf("dotted.\n");
//         break;
//     case DASHED:
//         printf("dashed.\n");
//         break;
//     default:
//         printf("unknown type.\n");
//     }
// }

// void show_settings1(unsigned short us)
// {
//     printf("box is %s.\n", (us & OPAQUE) == OPAQUE ? "opaque" : "transparent");
//     printf("The fill color is %s.\n", colors[(us >> 1) & 07]);
//     printf("Border %s.\n", (us & BORDER) == BORDER ? "shown" : "not shown");
//     printf("The border style is ");
//     switch (us & STYLE_MASK)
//     {
//     case B_SOLID:
//         printf("solid.\n");
//         break;
//     case B_DOTTED:
//         printf("dotted.\n");
//         break;
//     case B_DASHED:
//         printf("dashed.\n");
//         break;
//     default:
//         printf("unknown type.\n");
//     }
//     printf("The border color is %s.\n", colors[(us >> 9) & 07]);
// }

// char *itobs(int n, char *ps)
// {
//     int i;
//     const static int size = CHAR_BIT * sizeof(int);
//     for (i = size - 1; i >= 0; i--, n >>= 1)
//         ps[i] = (01 & n) + '0';
//     ps[size] = '\0';
//     return ps;
// }
