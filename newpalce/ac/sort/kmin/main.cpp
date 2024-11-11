#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    set<int> s;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        s.insert(temp);
    }
    int count = 0;
    auto it = s.begin();
    for (it = s.begin(); it != s.end(); it++)
    {
        count++;
        if (count == m)
        {
            break;
        }
    }
    if (it != s.end())
    {
        cout << *it;
    }
    else
    {
        cout << "NO RESULT";
    }
}