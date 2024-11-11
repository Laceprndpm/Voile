#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    int n;
    cin >> n >> n;
    vector<double> arr(n);
    std::ostream_iterator<int> out_it(std::cout, " ");
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    copy(arr.begin(), arr.end(), out_it);
}