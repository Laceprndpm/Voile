#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> row;
    set<int> col;
    int M, N, B, G;
    cin >> M >> N >> B >> G;
    for (int i = 0; i < B; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = x; j <= y; j++)
        {
            row.insert(j);
        }
    }
    for (int i = 0; i < G; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = x; j <= y; j++)
        {
            col.insert(j);
        }
    }
    cout << (row.size() * N + col.size() * M) - (row.size() * col.size());
}