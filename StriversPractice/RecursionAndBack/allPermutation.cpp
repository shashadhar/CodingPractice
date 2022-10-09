#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <map>

using namespace std;



void printSubset(vector<int> ar){
  for(auto s: ar){
    cout<< s<< " ";
    } 
  cout<<endl;

}

void allPermutation(vector<int> arr , int n , int i, vector<int> &allPer){

if(i == n){
 printSubset(arr);
}

for(int j =i ; j< n;j++){
   swap(arr[i], arr[j]);
   allPermutation(arr,n,i+1,allPer);
   swap(arr[i], arr[j]);
}


return ;
}


/*
Given an array arr of distinct integers, print all permutations of String/Array.

Examples:

Example 1: 

Input: arr = [1, 2, 3]

Output: 
[
  [1, 2, 3],
  [1, 3, 2],
  [2, 1, 3],
  [2, 3, 1],
  [3, 1, 2],
  [3, 2, 1]
]

Explanation: Given an array, return all the possible permutations.

Example 2:

Input: arr = [0, 1]

Output:
[
  [0, 1],
  [1, 0]
]

Explanation: Given an array, return all the possible permutations.*/

int main(){

  vector<int> arr = {1,2,3};
  vector<int> allPerm;
 allPermutation(arr,3,0,allPerm);
  
 
}