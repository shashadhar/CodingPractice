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
  int sum=0;
  for(auto s: ar){
    cout<< s<< " ";
    sum = sum + s;
  }
  cout<< ":"<< sum;
  cout<<endl;

}

void subsetSum(vector<int> arr , int n , int i, vector<int> &allSum, int sum){

if(i == n){
 allSum.push_back(sum); 
 cout<< sum<<" ";
 return;
}
if(i > n){
  return;
}

// we have two case include in output or exclude

// include
subsetSum(arr, n , i+1,allSum,sum+arr[i]);
//exclude
subsetSum(arr,n, i+1,allSum, sum);
return ;
}


/*
Given an array print all the sum of the subset generated from it, in the increasing order.

Examples:

Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8


Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6
*/

int main(){

  vector<int> arr = {5,2,1};
  vector<int> out;
  subsetSum(arr,3,0,out,0);
 
}