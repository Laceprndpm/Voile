#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

inline pair<int, int> extract(int index, int n)
{
    int row = index / n;
    int col = index % n;
    return {row, col};
}

int step1(Matrix &v, int index, int n, int target)
{
    auto [row, col] = extract(index, n);
    if (row == 0)
    {
        if (col != n - 1)
        {
            v[n - 1][col + 1] = target;
            return (n - 1) * n + col + 1;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

int step2(vector<vector<int>> &v, int index, int n, int target)
{
    auto [row, col] = extract(index, n);
    if (row != 0)
    {
        if (col == n - 1)
        {
            v[row - 1][0] = target;
            return (row - 1) * n;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

int step3(Matrix &v, int index, int n, int target)
{
    auto [row, col] = extract(index, n);
    if (row == 0 && col == n - 1)
    {
        v[row + 1][col] = target;
        return (row + 1) * n + col;
    }
    return -1;
}
int step4(Matrix &v, int index, int n, int target)
{
    auto [row, col] = extract(index, n);
    if (row != 0 && col != n - 1)
    {
        if (v[row - 1][col + 1] == 0)
        {
            v[row - 1][col + 1] = target;
            return (row - 1) * n + col + 1;
        }
        else
        {
            v[row + 1][col] = target;
            return (row + 1) * n + col;
        }
        return row * n + col - 1;
    }
    return -1;
}
int handle(Matrix &v, int index, int n, int target)
{
    int temp;
    temp = step1(v, index, n, target);
    if (temp != -1)
    {
        return temp;
    }
    temp = step2(v, index, n, target);
    if (temp != -1)
    {
        return temp;
    }
    temp = step3(v, index, n, target);
    if (temp != -1)
    {
        return temp;
    }
    temp = step4(v, index, n, target);
    if (temp != -1)
    {
        return temp;
    }
    throw "error";
}
void display(const Matrix &v)
{
    for (const auto &row : v)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    v[0][n / 2] = 1;
    int index = n / 2;
    for (int i = 2; i <= n * n; i++)
    {
        index = handle(v, index, n, i);
    }
    display(v);
}