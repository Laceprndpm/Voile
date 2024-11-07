// #include <stdio.h>
// int main()
// {
//     FILE *ptr;
//     char arr[10];
//     ptr = fopen("super.txt", "r");
//     printf("%s", fgets(arr, 10, ptr));
//     printf("%d\n", fgetc(ptr));
//     printf("test");
// }
#define PRINT(X) printf("The value of "#X" is %d", X)
#include <stdio.h>
int main()
{
    int a = 2;
    PRINT(a);
    getchar();
}