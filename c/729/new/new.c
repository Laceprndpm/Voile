#include <stdio.h>
int main()
{
    char arr1[5] = {0};
    char *arr2[5] = {NULL};
    char(*pa)[5] = &arr1;
    char *(*pb)[5] = &arr2;
    *pa++;
}
