#include <iostream>
int contains(int src, const int &target)
{
    if (src == 0)
    {
        return 0;
    }
    return src % 10 == target ? 1 + contains(src / 10, target) : contains(src / 10, target);
}
int main()
{
    int start, end;
    long long int count = 0;
    std::cin >> start >> end;
    for (int i = start; i <= end; i++)
    {
        count += contains(i, 2);
    }
    std::cout << count << std::endl;
    return 0;
}