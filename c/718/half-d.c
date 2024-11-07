#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int k = 7;
    int noa = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = noa - 1;
    while (1)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            printf("Found!It's arr[%d]", mid);
            break;
        }
        if (arr[left] > k)
        {
            printf("Failed to find!");
            break;
        }
    }
}