#include <set>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef struct Integer
{
    int data;
    bool operator<(const Integer &other) const
    {
        return data > other.data;
    }
} Integer;

int main()
{
    priority_queue<Integer> minHeap;
    int numofheaps;
    int temp;
    cin >> numofheaps;
    for (int i = 0; i < numofheaps; i++)
    {
        cin >> temp;
        minHeap.push(Integer{temp});
    }
    Integer a, b, c;
    int count = 0;
    while (minHeap.size() != 1)
    {
        a = minHeap.top();
        minHeap.pop();
        b = minHeap.top();
        minHeap.pop();
        count += a.data + b.data;
        c = Integer{a.data + b.data};
        minHeap.push(c);
    }
    cout << count;
}