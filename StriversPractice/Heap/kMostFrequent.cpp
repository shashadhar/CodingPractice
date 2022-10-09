#include<bits/stdc++.h>

using namespace std;
#include<bits/stdc++.h>

using namespace  std;
class compare {

public:    
bool operator()(pair<int,int> p1 , pair<int,int> p2){
    return p1.second < p2.second;
}
};

void kMostFrequentEle(vector<int> ar, int k){
  

  unordered_map<int,int> fr;

  

  // find the frequency first
  for (auto s : ar)
  {
    fr[s]++;
  }

  // now store in max heap
  priority_queue<pair<int,int>, vector<pair<int,int>> , compare> maxHeap;

  for (auto s : fr)
  {
    maxHeap.push({s.first, s.second});
  }
  

  // get the k most frequent element

  for(int i=0;i<k;i++){
    pair<int,int> p = maxHeap.top();
    cout<< p.first << ":" <<p.second <<endl;
    maxHeap.pop(); 
  }

}


/**
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

 */
int main(){

    vector <int> el = {1,1,1,2,2,3};
    kMostFrequentEle(el,2);

}