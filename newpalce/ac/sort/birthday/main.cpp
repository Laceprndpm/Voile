#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct date
{
    int year;
    int month;
    int day;
    date(int y, int m, int d) : year(y), month(m), day(d) {}
    bool operator<(const date &d) const
    {
        if (year != d.year)
            return year < d.year;
        if (month != d.month)
            return month < d.month;
        return day < d.day;
    }
};

int main()
{
    int n;
    cin >> n;
    int y, m, d;
    string name;
    vector<pair<string, date>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> y >> m >> d;
        v.push_back(make_pair(name, date(y, m, d)));
    }
    stable_sort(v.rbegin(), v.rend(), [](const pair<string, date> &a, const pair<string, date> &b) {
        return a.second < b.second;
    });
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        cout << it->first << endl;
    }
}