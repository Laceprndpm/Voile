#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    sort(arr1.begin(), arr1.end());
    int temp;
    ll sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        auto it1 = lower_bound(arr1.begin(), arr1.end(), temp);
        if (it1 == arr1.end())
        {
            it1 = arr1.end() - 1;
        }
        auto it2 = it1;
        if (it1 != arr1.begin())
        {
            it2 = it1 - 1;
        }
        int value1 = abs(*it1 - temp);
        int value2 = abs(temp - *it2);
        int small = min(value1, value2);
        sum += small;
    }
    cout << sum;
}