#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int minCostMergingRopes(vector<int> ropes)
{
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());

    int minCost = 0;
    while (minHeap.size() > 1)
    {
        int smallestRope1 = minHeap.top();
        minHeap.pop();

        int smallestRope2 = minHeap.top();
        minHeap.pop();
        int cost = smallestRope1 + smallestRope2;
        minCost = minCost + cost;
        minHeap.push(cost);
    }

    return minCost;
}

int main()
{

    vector<int> ropes = {4, 3, 2, 6};
    cout << "Min cost:" << minCostMergingRopes(ropes);
}