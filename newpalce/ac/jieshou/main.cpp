#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int main()
{
    // if (!freopen(".\\P1190_10.in", "r", stdin))
    // {
    //     cerr << "Error opening input file" << endl;
    //     return 1;
    // }
    int n, m; // people, taps
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int currenttime = 0;
    int donepeople = 0;
    int currentpeople = 0;
    do
    {
        if (minHeap.size() < m && currentpeople < n) // if there are still people and taps
        {
            minHeap.push(arr[currentpeople] + currenttime); // push the people's time when the tap will be free
            currentpeople++;                                // next person in line
        }
        else // if there are no taps or people
        {
            currenttime = minHeap.top(); // get the time when the tap will be free
            minHeap.pop();               // remove the people from the tap
            donepeople++;                // one more person is done
        }
    } while (donepeople != n); // while there are still people in line
    cout << currenttime; // output the time when the last person will be done
    return 0;
}