#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

vector<int> mergeKSortedList(vector<vector<int>> ar, int k)
{
    vector<int> sortedArray;

    // contains triplet {element,index,arrayindex}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

    // push first k elementes
    for (int i = 0; i < k; i++)
    {
        minHeap.push({ar[i][0], 0, i});
    }

    while (!minHeap.empty())
    {
        vector<int> popedMinElement = minHeap.top();
        int arrayIndex = popedMinElement[2];
        int index = popedMinElement[1];
        int element = popedMinElement[0];

        minHeap.pop();

        // insert into the sorted list
        sortedArray.push_back(element);

        // get the next element for the array and push to min heap
        if (index + 1 < ar[arrayIndex].size())
        {
            vector<int> elementToPush = {ar[arrayIndex][index + 1], index + 1, arrayIndex};
            minHeap.push(elementToPush);
        }
    }

    return sortedArray;
}

int main()
{

    vector<int> a1 = {1, 3, 15};
    vector<int> a2 = {2, 4, 6};
    vector<int> a3 = {0, 9, 10, 11};
    vector<vector<int>> arrays = {a1, a2, a3};

    vector<int> a = mergeKSortedList(arrays, 3);
    for (auto s : a)
    {
        cout << s << " ";
    }
}