// // 为了准备一个独特的颁奖典礼，组织者在会场的一片矩形区域（可看做是平面直角坐标系的第一象限）铺上一些矩形地毯。一共有 nn 张地毯，编号从 11 到 nn。现在将这些地毯按照编号从小到大的顺序平行于坐标轴先后铺设，后铺的地毯覆盖在前面已经铺好的地毯之上。

// //     地毯铺设完成后，组织者想知道覆盖地面某个点的最上面的那张地毯的编号。注意：在矩形地毯边界和四个顶点上的点也算被地毯覆盖。
// #include <iostream>
// #include <map>
// using namespace std;
// // typedef struct point
// // {
// //     int x, y;
// // } point;
// // bool operator<(const point &a, const point &b)
// // {
// //     if (a.x < b.x)
// //         return 1;
// //     else if (a.x == b.x)
// //     {
// //         if (a.y < b.y)
// //             return 1;
// //         else
// //             return 0;
// //     }
// //     else
// //         return 0;
// // }

// struct point
// {
//     int x, y;

//     // 定义 < 运算符
//     bool operator<(const point &other) const
//     {
//         if (x < other.x)
//         {
//             return true;
//         }
//         else if (x == other.x)
//         {
//             return y < other.y;
//         }
//         else
//         {
//             return false;
//         }
//     }
// };

// int main()
// {
//     int n;
//     cin >> n;
//     map<point, int> m;
//     for (int k = 0; k < n; k++)
//     {
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         for (int i = 0; i <= x2; i++)
//         {
//             for (int j = 0; j <= y2; j++)
//             {
//                 point p{x1 + i, y1 + j};
//                 if (m.find(p) != m.end())
//                     m[p] = m[p] + 1;
//                 else
//                     m.insert(pair<point, int>(p, 1));
//             }
//         }
//     }
//     int x, y;
//     cin >> x >> y;
//     m.find(point{x, y}) == m.end() ? cout << -1 : cout << m[point{x, y}];
//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
typedef struct point
{
    int x, y;
} point;
using namespace std;

class carpet
{
private:
    int x, y, lenth, width;

public:
    carpet(int x, int y, int lenth, int width) : x(x), y(y), lenth(lenth), width(width) {};
    ~carpet() {};
    bool contains(point p)
    {
        return p.x >= x && p.x <= x + lenth && p.y >= y && p.y <= y + width;
    }
};

int main()
{
    vector<carpet> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, lenth, width;
        cin >> x >> y >> lenth >> width;
        v.push_back(carpet(x, y, lenth, width));
    }
    point p;
    cin >> p.x >> p.y;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i].contains(p))
        {
            cout << i + 1;
            return 0;
        }
    }
}