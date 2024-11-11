#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int pi = 0;
    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        temp += arr[i];
    }
    int min = temp;
    for (pi = 0; pi < n - m; pi++)
    {
        temp -= arr[pi];
        temp += arr[pi + m];
        if (temp < min)
        {
            min = temp;
        }
    }
    cout << min;
}