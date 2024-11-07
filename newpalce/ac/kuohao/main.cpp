#include <iostream>
#include <string>

int countParentheses(const std::string &str)
{
    int count = 0;
    for (char ch : str)
    {
        if (ch == '(')
        {
            count++;
        }
        else if (ch == ')')
        {
            count--;
        }
        if (ch == '@')
        {
            return count;
        }
        if (count < 0)
        {
            return -1;
        }
        }
    return count;
}

int main()
{
    std::string input;
    std::getline(std::cin, input);

    int result = countParentheses(input);
    if (result != 0)
    {
        std::cout << "NO" << std::endl;
    }
    else
    {
        std::cout << "YES" << std::endl;
    }
    return 0;
}
