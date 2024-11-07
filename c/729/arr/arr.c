#include <stdio.h>

// 函数定义，形参为 arr[3][4]
void printArray(int arr[3][4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // 定义一个大小为 [4][3] 的二维数组
    const int myArray[4][3] = {
        {1, 2, 3
}
,
    {4, 5, 6},
    {7, 8, 9},
{
    10, 11, 12}};

    // 调用函数，传递 myArray 作为实参
    printArray(myArray);

    return 0;
}