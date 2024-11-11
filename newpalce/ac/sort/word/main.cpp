#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_set<string> uno;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        uno.insert(s);
    }
    cout << uno.size();
}