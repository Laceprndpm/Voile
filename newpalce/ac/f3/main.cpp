#include <iostream>
#include <vector>
#include <algorithm>

int vectorToInt(const std::vector<int> &numbers)
{
    int result = 0;
    for (int num : numbers)
    {
        result = result * 10 + num;
    }
    return result;
}
int main()
{
    // 初始化包含数字 1 到 9 的向量
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 使用 do-while 循环生成并输出所有排列组合
    do
    {
        int temp;
        std::vector<int> n1(numbers.begin(), numbers.begin() + 3);
        std::vector<int> n2(numbers.begin() + 3, numbers.begin() + 6);
        std::vector<int> n3(numbers.begin() + 6, numbers.end());
        int num1 = vectorToInt(n1);
        int num2 = vectorToInt(n2);
        int num3 = vectorToInt(n3);
        if (num1 * 2 == num2 && num1 * 3 == num3)
        {
            std::cout << num1 << " " << num2 << " " << num3 << std::endl;
        }
    } while (std::next_permutation(numbers.begin(), numbers.end()));

    return 0;
}