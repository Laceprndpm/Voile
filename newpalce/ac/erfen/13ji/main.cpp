#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
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
    int temp;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        auto it = lower_bound(arr.begin(), arr.end(), temp);
        if (*it != temp)
        {
            cout << -1 << " ";
            continue;
        }
        cout << it - arr.begin() + 1 << " ";
    }
}