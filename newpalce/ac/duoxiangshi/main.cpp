#include <iostream>
#include <vector>
#include <string>
#include <cmath>

void duoxiangshi(const std::vector<int> &coefficients)
{
    int n = coefficients.size() - 1;
    bool firstTerm = true;

    for (int i = 0; i <= n; ++i)
    {
        int coeff = coefficients[i];
        int power = n - i;

        if (coeff == 0)
        {
            continue;
        }

        if (firstTerm)
        {
            if (coeff < 0)
            {
                std::cout << "-";
            }
            firstTerm = false;
        }
        else
        {
            if (coeff > 0)
            {
                std::cout << "+";
            }
            else
            {
                std::cout << "-";
            }
        }

        if (std::abs(coeff) != 1 || power == 0)
        {
            std::cout << std::abs(coeff);
        }

        if (power > 0)
        {
            std::cout << "x";
            if (power > 1)
            {
                std::cout << "^" << power;
            }
        }
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> coefficients(n + 1);

    for (int i = 0; i <= n; ++i)
    {
        std::cin >> coefficients[i];
    }

    duoxiangshi(coefficients);

    return 0;
}