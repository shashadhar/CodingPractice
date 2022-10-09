#include <bits/stdc++.h>


using namespace std;


int searchInRotatedSortedArrayElement(int n, vector<int> ar,int target){
    int s = 0;
    int e = n;
    int mid = (s +e)/2;
    while (e>=s)
    {
        // 
        if(ar[mid] == target){
            return mid;
        }

        // check 1st line i.e left rotated large line
        if( ar[s] <=ar[mid] ){
             if(ar[s] <= target <= ar[mid]){
              e = mid -1;
            }else{
                s = mid + 1;
            }
        // check the 2nd line which is smaller elements line i.e right line    
        }else if(ar[e]>=ar[mid]){
           if(ar[e] >= target <=ar[mid]){
             e = mid -1 ;
           }else{
            s = mid +1;
           }
        }
       mid = (s+e)/2; 
    }
  return -1;  
}

/*
There is an integer array nums sorted in ascending order (with distinct values). Given the array nums after the possible clockwise rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums. We need to search a given element in a rotated sorted array.

Example 1:

Input: nums = [4,5,6,7,0,1,2,3], target = 0

Output: 4

Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3

Output: -1 

Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get output as -1.
*/
int main()
{
    vector<int> s = {4,5,6,7,0,1,2,3} ;
    cout << searchInRotatedSortedArrayElement(8,s,0);
}