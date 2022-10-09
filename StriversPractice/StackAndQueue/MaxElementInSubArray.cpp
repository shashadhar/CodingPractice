#include<bits/stdc++.h>

using namespace std;


/*
Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Examples:

Example 1:

Input: arr = [4,0,-1,3,5,3,6,8], k = 3

Output: [4,3,5,5,6,8]

Explanation: 

Window position                   Max
------------------------         -----
[4  0  -1] 3  5  3  6  8           4
 4 [0  -1  3] 5  3  6  8           3
 4  0 [-1  3  5] 3  6  8           5
 4  0  -1 [3  5  3] 6  8           5
 4  0  -1  3 [5  3  6] 8           6
 4  0  -1  3  5 [3  6  8]          8

For each window of size k=3, we find the maximum element in the window and add it to our output array.

Example 2:

Input: arr= [20,25], k = 2

Output: [25]

Explanation: There’s just one window is size 2 that is possible and the maximum of the two elements is our answer.
*/
void maxElementInSubArray(vector<int> el, int k){
  deque<int> maxD(k);
  int i;
  for(i =0; i< k ; i++){
   while (!maxD.empty() && el[maxD.back()] < el[i])
   {
      maxD.pop_back();
   }
   maxD.push_back(i);
  }


   // remaining element
  

   for(;i<el.size();i++){

       cout<< el[maxD.front()]<<endl;

    while (!maxD.empty() && maxD.front() <= i-k)
   {
      maxD.pop_front();
   }
   

   while (!maxD.empty() && el[maxD.back()] <= el[i])
   {
      maxD.pop_back();
   }
   maxD.push_back(i);

   }
   
  
}


int  main(){
   vector<int> arr={4,0,-1,3,5,3,6,8};
    int k =3;
    maxElementInSubArray(arr,k);
}