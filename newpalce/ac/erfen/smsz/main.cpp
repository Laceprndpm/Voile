// #include <iostream>
// #include <vector>
// #include <algorithm>
// typedef long long ll;
// // 暴力
// using namespace std;
// ll check(const vector<int>::iterator start, const vector<int>::iterator end, const int M, const vector<int>::iterator finalend);
// ll check(const vector<int>::iterator justone, const int M, const vector<int>::iterator finalend)
// {
//     return check(justone, (vector<int>::iterator)(justone + 1), M, finalend);
// }
// ll check(const vector<int>::iterator start, const vector<int>::iterator end, const int M, const vector<int>::iterator finalend)
// {
//     ll sum = 0;
//     for (auto it = start; it != end; it++)
//     {
//         sum += *it;
//     }
//     double avg = (double)sum / (end - start);
//     if (avg > M)
//     {
//         if (end != finalend)
//         {
//             return check(start, end + 1, M, finalend) + 1;
//         }
//         else
//         {
//             return 1;
//         }
//     }
//     else
//     {
//         if (end != finalend)
//         {
//             return check(start, end + 1, M, finalend);
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     throw "error";
// }
// int main()
// {
//     int n, M;
//     cin >> n >> M;
//     vector<int> arr(n);
//     ll sum = 0;
//     for (size_t i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (auto it = arr.begin(); it != arr.end(); it++)
//     {
//         sum += check(it, M, arr.end());
//     }
//     cout << sum % 92084931;
// }
