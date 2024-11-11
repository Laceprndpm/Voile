#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> food(n);

    for (int i = 0; i < n; i++)
    {
        cin >> food[i];
    }

    sort(food.rbegin(), food.rend());

    double sum = 0;
    int m = 0;
    double maxComfort = 0;

    for (int i = 0; i < n; i++)
    {
        sum += food[i];
        m++;
        double comfort = (sum * sum) / m;
        if (comfort > maxComfort)
        {
            maxComfort = comfort;
        }
        else
        {
            break;
        }
    }

    cout << fixed << setprecision(10) << maxComfort << endl;

    return 0;
}