#include <bits/stdc++.h>

using namespace std;

// Best solution

vector<int> kMaxSumCombEfficient(vector<int> &A, vector<int> &B, int C)
{
    // sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    vector<int> ans;
    // take max heap
    priority_queue<pair<int, pair<int, int>>> maxh;
    // take set
    set<pair<int, int>> st;
    // push the maximum possible sum
    maxh.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    // store index of same
    st.insert(make_pair(n - 1, n - 1));
    // run loop exactly c times, every times we get a part of answer
    for (int count = 0; count < C; count++)
    {
        // read top of max heap
        auto nd = maxh.top();
        maxh.pop();
        // here is a part of answer
        ans.push_back(nd.first);
        int i = nd.second.first;
        int j = nd.second.second;
        // taking sum of next maximum element of A keeping same element of B
        int temp1 = A[i - 1] + B[j];
        if (st.find(make_pair(i - 1, j)) == st.end())
        {
            maxh.push({temp1, {i - 1, j}});
            st.insert(make_pair(i - 1, j));
        }
        // taking sum of next maximum element of B keeping same element of A
        int temp2 = A[i] + B[j - 1];
        if (st.find(make_pair(i, j - 1)) == st.end())
        {
            maxh.push({temp2, {i, j - 1}});
            st.insert(make_pair(i, j - 1));
        }
    }
    // return answer
    return ans;
}

// this may give TLE in some cases
void kMaxSumCombination(vector<int> a1, vector<int> a2, int k)
{

    priority_queue<int, vector<int>> maxHeap;

    // create all the sum combination and push to maxheap
    for (int i = 0; i < a1.size(); i++)
    {
        for (int j = 0; j < a2.size(); j++)
        {
            int sum = a1[i] + a2[j];
            maxHeap.push(sum);
        }
    }

    for (int p = 0; p < k; p++)
    {
        cout << maxHeap.top() << endl;
        maxHeap.pop();
    }
}

/**
Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.

A = [3, 2]
 B = [1, 4]
 C = 2

 [7, 6]

  A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4
  [10, 9, 9, 8]

 */

int main()
{

    vector<int> a1 = {1, 4, 2, 3};
    vector<int> a2 = {2, 5, 1, 6};
    kMaxSumCombination(a1, a2, 4);
}