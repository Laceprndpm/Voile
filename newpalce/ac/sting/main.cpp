#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n;
    string s1, s2, s3;
    cin >> n >> s1 >> s2;
    s3.resize(n);
    transform(s1.begin(), s1.end(), s2.begin(), s3.begin(), [](char a, char b)
              { return a < b ? a : b; });
    if (s3 == s2)
    {
        cout << s2;
    }
    else
    {
        cout << -1;
    }
}
