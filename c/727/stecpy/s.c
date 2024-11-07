#include <stdio.h>
#include<string.h>
// void my_strcpy(char arr1[],const char arr2[])
// {
//     int i = 0;
//     while (arr2[i] != '\0')
//     {
//         arr1[i] = arr2[i];
//         i++;
//     }
//     arr1[i] = arr2[i];
// }
int main()
{
    // strcpy
    // 字符串拷贝
    char arr1[] = "###########";
    char arr2[] = "bit";
    strcpy(arr1, arr2);
    printf("%s", arr1);
}