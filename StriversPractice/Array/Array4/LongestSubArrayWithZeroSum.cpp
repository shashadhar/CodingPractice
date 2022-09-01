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

int lengthLongestSubarrayWithZeroSum(vector<int> ar, int k){
    unordered_map<int,int> prevSum;
    int maxLength = 0;
    int currentSum;
    for(int i=0;i< ar.size(); i++){
       currentSum = currentSum + ar[i];
       if(currentSum == k){
          maxLength = max(maxLength,i +1);
       }else if(prevSum.find(currentSum)!= prevSum.end()){
           maxLength = max(maxLength, (i - prevSum[currentSum]));
       } else{
           prevSum[currentSum] = i;
       }

    }
    return maxLength;
}



/**Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Example 1:

Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}

Result: 5

Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5! **/

int main(){

 vector<int> ar = {9, -3, 3, -1, 6, -5}  ;
 cout<<lengthLongestSubarrayWithZeroSum(ar,0);


    
}
