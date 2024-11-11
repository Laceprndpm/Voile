#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int a, b;
    vector<pair<int, int>> arr;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first < b.first; });
    stable_sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b)
                { return a.second > b.second; });
    int target = arr[n * 1.5 - 1].second;
    auto it = arr.begin() + static_cast<int>(n * 1.5 - 1);
    while (it + 1 != arr.end() && it->second == (it + 1)->second)
    {
        it++;
    }
    int i = 0;
    cout << target << " " << (int)(it - arr.begin()) + 1 << endl;

    while (arr[i].second >= target)
    {
        cout << arr[i].first << " " << arr[i].second << endl;
        i++;
    }
    return 0;
}