#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

void priorityQueue()
{
    vector<int> arr = {12, 89, 56, 34, 2, 5, 9};

    priority_queue<int, vector<int>, Compare> heap;
    for (auto s : arr)
    {
        heap.push(s);
    }

    while (!heap.empty())
    {
        cout << heap.top() << endl;
        heap.pop();
    }
}

int main()
{
    priorityQueue();
}