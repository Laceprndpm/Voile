// #include<stdio.h>
// void print_arr(int rows, int cols, int arr[rows][cols]);
// int main()
// {
//     int arr[2][2] = {0};
//     print_arr(2, 2, arr);
// }
// void print_arr(int rows,int cols,int arr[rows][cols])
// {
//     for (int i = 0; i < rows;i++)
//     {
//         for (int j = 0; j < cols;j++)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
// }
// #include <stdio.h>
// int main()
// {
//     char *p1 = "Klingon";
//     p1[0] = 'F'; // ok?
//     printf("Klingon");
//     printf(": Beware the %ss!\n", "Klingon");
// }
// #include <stdio.h>

// int main()
// {
//     ;
//     char *test = "charxx";
//     puts(test);
//     puts(test);
//     fputs("chaxxx", stdout);
//     puts(test);
// }
/* fgets2.c -- 使用 fgets() 和 fputs() */

#include <stdio.h>
#define STLEN 10
int main(void)
{
    char words[STLEN];
    puts("Enter strings (empty line to quit)呵呵:");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Done.");
    return 0;
}