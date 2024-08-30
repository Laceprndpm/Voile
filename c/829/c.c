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
#include <wchar.h>
#include <stdio.h>

struct person
{
    wchar_t name[20];
    char username[20];
    char password[20];
    int arr[60];
};

void test(const struct person *);

int main()
{
    struct person p = {
        L"小明", // 使用宽字符字符串
        "tttt",
        "123456",
        {1, 2, 3} // 直接初始化数组
    };
    struct person *pt;
    pt = &p;
    test(pt);
}

void test(const struct person *ptr)
{
    puts(ptr->username);
    puts(ptr->password);
}
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