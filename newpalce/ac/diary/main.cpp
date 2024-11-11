#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Compare
{
    bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

int main()
{
    int n, m;
    using farmer = std::pair<int, int>;
    std::cin >> n >> m;
    std::vector<int> arr(n);
    std::priority_queue<farmer, std::vector<farmer>, Compare> minHeap;
    int p, q;
    for (int i = 0; i < m; i++)
    {
        std::cin >> p >> q;
        std::pair<int, int> temp(p, q);
        minHeap.push(temp);
    }
    int money = 0;
    while (n != 0)
    {
        if (n > minHeap.top().second)
        {
            n -= minHeap.top().second;
            money += minHeap.top().second * minHeap.top().first;
            minHeap.pop();
        }
        else
        {
            money += n * minHeap.top().first;
            n = 0;
        }
    }
    std::cout << money;
}