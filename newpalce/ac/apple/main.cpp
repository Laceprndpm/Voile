#include <iostream>
#include <set>
#include <algorithm>
int main()
{
    int n, s, a, b;
    std::multiset<int> Sset;
    std::cin >> n >> s >> a >> b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (x <= a + b)
        {
            Sset.insert(y);
        }
    }
    int count = 0;
    for (auto it = Sset.begin(); it != Sset.end(); it++)
    {
        if (s >= *it)
        {
            s -= *it;
            count++;
        }
        else
        {
            break;
        }
    }
    std::cout << count << std::endl;
}