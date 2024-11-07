#include <stdio.h>
void bubble(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int flag = 1;
        int j = 0;
        for (j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble(arr, sz);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }
}