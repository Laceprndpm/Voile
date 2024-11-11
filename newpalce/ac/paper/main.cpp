#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> cards(N);
    int total = 0;

    // 输入每堆纸牌的数量
    for (int i = 0; i < N; ++i)
    {
        std::cin >> cards[i];
        total += cards[i];
    }

    // 计算每堆纸牌的平均数
    int average = total / N;
    int moves = 0;
    int count = 0;
    // 从左到右遍历每堆纸牌
    for (int i = 0; i < N - 1; ++i)
    {
        int diff = cards[i] - average;
        cards[i + 1] += diff;
        moves += std::abs(diff);
        if (diff)
        {
            count++;
        }
        }

    std::cout << count << std::endl;
    return 0;
}