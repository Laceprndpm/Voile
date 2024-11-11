// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// using namespace std;
// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
//     priority_queue<int, vector<int>, less<int>> maxHeap(arr.begin(), arr.end());
//     int offset = 0;
//     int temp;
//     int ml;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> ml;
//         switch (ml)
//         {
//         case 3:
//         {
//             cout << n << endl;
//             break;
//         }
//         case 2:
//         {
//             cin >> temp;
//             offset += temp;
//             while (minHeap.top() < offset - k)
//             {
//                 minHeap.pop();
//                 n--;
//             }
//             break;
//         }
//         case 1:
//         {
//             cin >> temp;
//             offset -= temp;
//             while (maxHeap.top() > k + offset)
//             {
//                 maxHeap.pop();
//                 n--;
//             }
//             break;
//         }
//         default:
//         {
//             throw "error";
//             break;
//         }
//         }
//     }
// }
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     sort(arr.begin(), arr.end());
//     auto start = arr.begin();
//     auto end = arr.end();
//     int offset = 0;
//     start = lower_bound(start, end, offset - k);
//     end = upper_bound(start, end, k + offset);
//     n = end - start;
//     int temp;
//     int ml;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> ml;
//         switch (ml)
//         {
//         case 3:
//         {
//             cout << n << endl;
//             break;
//         }
//         case 2:
//         {
//             cin >> temp;
//             offset += temp;
//             start = lower_bound(start, end, offset - k);
//             n = end - start;
//             break;
//         }
//         case 1:
//         {
//             cin >> temp;
//             offset -= temp;
//             end = upper_bound(start, end, k + offset);
//             n = end - start;
//             break;
//         }
//         default:
//         {
//             throw "error";
//             break;
//         }
//         }
//     }
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long offset = 0;
    auto start = arr.begin();
    auto end = arr.end();

    for (int i = 0; i < m; i++)
    {
        int op;
        long long x;
        cin >> op;
        if (op == 1 || op == 2)
        {
            cin >> x;
            if (op == 1)
            {
                offset -= x;
            }
            else
            {
                offset += x;
            }
            start = lower_bound(start, end, offset - k);
            end = upper_bound(start, end, k + offset);
            n = end - start;
        }
        else if (op == 3)
        {
            cout << n << endl;
        }
    }

    return 0;
}
