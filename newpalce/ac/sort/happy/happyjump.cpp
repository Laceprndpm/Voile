#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int prevalue, value;
    int times;
    int n = 0;
    vector<int> arr;
    cin >> times;
    cin >> prevalue;
    while (--times)
    {
        cin >> value;
        arr.push_back(abs(prevalue - value));
        n++;
        prevalue = value;
    }
    sort(arr.begin(), arr.end());
    auto it = unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());
    if (arr.size() == n && arr[0] == 1 && arr[n - 1] == n)
        cout << "Jolly";
    else if (n == 0)
    {
        cout << "Jolly";
    }
    else
    {
        cout << "Not jolly";
    }
}