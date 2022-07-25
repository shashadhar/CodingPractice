#include<iostream>
#include <string>
#include<stack>
#include<vector>
#include <deque>
#include<unordered_map>

using namespace std;

void maxElementInSubArray(vector<int> arr, int k){
    vector<int> result;
    deque<int> maxEleDeq(k);

    // for 1st k elements
    int i;
    for(i=0;i<k;i++){
        while(!maxEleDeq.empty() &&  arr[maxEleDeq.back()] < arr[i]){
            maxEleDeq.pop_back();
        }
        maxEleDeq.push_back(i);
        
    }
 
   // for remaining elements
   for(;i<arr.size();i++){
       cout<< arr[maxEleDeq.front()]<<" ";

       // delete from deque whose index is out of range of sub array
        while(!maxEleDeq.empty() && maxEleDeq.front()<=i - k){
            maxEleDeq.pop_front();
        }
       
       while(!maxEleDeq.empty() && arr[maxEleDeq.back()] <= arr[i]){
            maxEleDeq.pop_back();
        }
    maxEleDeq.push_back(i);
        

   }

}

// max element in all the sub arrays
int main(){
    vector<int> arr={1,2,3,1,4,5,2,3,5};
    int k =3;
    maxElementInSubArray(arr,k);

}

