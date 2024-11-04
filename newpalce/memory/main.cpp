#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::ostream_iterator<int, char> out(std::cout, " ");
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto &i : v)
    {
        *out++ = i;
    }
    int m = 1;
    char n = 1 + '0';
    std::cout << m;
    std::cout << n;
    return 0;
}