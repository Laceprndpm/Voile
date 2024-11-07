#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
pair<int, string> check(string s)
{
    string temp = s;
    int count = 0;
    // transform(s.begin(), s.end(), temp.begin(), [&count](char c)
    //           { return c == '1' ? count++, '1' : (c == '0' ? '1' : c); }); // 如果找到1，count++,如果0,直接改成1
    int size = s.size();
    for (auto it = s.begin(), it2 = temp.begin(); it != s.end(); it2++, it++)
    {
        if (*it == '1' || *it == '0')
        {
            *it == '1' ? count++ : 0;
            *it2 = '1';
        }
        else
        {
            *it2 = ' ';
        }
    }

    return {count, temp};
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        int length;
        cin >> length;
        cin.ignore();
        string s;
        getline(cin, s);
        auto temp = check(s);
        cout << temp.first << endl;  // '1'的数量
        cout << temp.second << endl; // 最后的字符串
    }
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // 计算最长连续 1 子段的长度
// int longestConsecutiveOnes(const vector<int>& arr) {
//     int maxLen = 0, currentLen = 0;
//     for (int num : arr) {
//         if (num == 1) {
//             currentLen++;
//             maxLen = max(maxLen, currentLen);
//         } else {
//             currentLen = 0;
//         }
//     }
//     return maxLen;
// }

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         int n;
//         cin >> n;
//         vector<int> arr(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> arr[i];
//         }

//         // 初始最长连续 1 子段的长度
//         int initialLongest = longestConsecutiveOnes(arr);

//         // 计算初始 0 的个数
//         int initialZeros = count(arr.begin(), arr.end(), 0);

//         // 尝试将所有 0 修改为 1
//         vector<int> modifiedArr = arr;
//         for (int i = 0; i < n; ++i) {
//             if (modifiedArr[i] == 0) {
//                 modifiedArr[i] = 1;
//             }
//         }

//         // 计算修改后的最长连续 1 子段的长度
//         int modifiedLongest = longestConsecutiveOnes(modifiedArr);

//         // 计算 x - y 的最大值
//         int maxXY = modifiedLongest - initialZeros;

//         // 输出结果
//         cout << maxXY << endl;
//         for (int num : modifiedArr) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int t, temp, i, j, n, x, y, num0, num1;
//     cin >> t;
//     for (i = 0; i < t; i++)
//     {
//         num0 = num1 = 0;
//         cin >> n;
//         for (j = 0; j < n; j++)
//         {
//             cin >> temp;
//             if (temp)
//             {
//                 num1++;
//             }
//             else
//             {
//                 num0++;
//             }
//         }
//         cout << num0 << endl;
//         for (j = 0; j < n; j++)
//         {
//             cout << "1 ";
//         }
//         cout << endl;
//     }
//     return 0;
// }