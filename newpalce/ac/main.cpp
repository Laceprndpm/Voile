#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    bool flag = false; // 判断有没有容身之地
    cin >> n;
    int a[n + 1][n + 1];
    memset(a, 0, sizeof(a)); // 数组初始化
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
                flag = true; // 表示有容身之地
        }
    }
    if (!flag)
        cout << "Bad Game!" << endl; // 如果flag为假按要求输出
    else
    {
        // 否则遍历数组的每一个元素
        int ans = 0; // 记录最大答案
        int tmp;     // 打擂用的
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 0) // 如果有位置，计算行列值，存进tmp里
                {
                    tmp = 0;
                    for (int m = 1; m <= n; m++)
                    {
                        tmp += a[i][m]; // 计算能攻击到的敌人
                        tmp += a[m][j];
                    }
                    ans = max(ans, tmp); // 打擂
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}