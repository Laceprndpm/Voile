// #include<stdio.h>
// #include<stdlib.h>
// int ch(const void *x,const void *y);
// int main()
// {
//     int (*pch)(const void *,const void *)=ch;
//     char arr[] = {'a', 'b', 'd', 'e','c'};
//     qsort(arr, 5, sizeof(char),pch);
// }
// int ch(const void*x,const void* y)
// {
//     return (*(char*)x - *(char*)y);
// }
#include  <stdio.h>

int main(int argc, char *argv[])

{

    int count;

    printf("The command line has %d arguments:\n", argc - 1);

for
     (count = 1; count < argc; count++)

        printf("%d: %s\n", count, argv[count]);

printf("\n");

return 0;
}