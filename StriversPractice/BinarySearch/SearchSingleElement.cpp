#include <bits/stdc++.h>


using namespace std;


int searchSingleElement(int n, vector<int> ar){
    int s = 0;
    int e = n;
    int mid = (s +e)/2;
    while (e>=s)
    {
        // check left and right of mid
        if( mid > 0 &&  ar[mid-1] == ar[mid]){
            // mid ele start position is odd mean single element on left side
            if((mid-1) % 2 == 1){
              e = mid -1;
            }else{
                s = mid + 1;
            }
        }else if(mid < n -1 &&  ar[mid+1] == ar[mid]){
           if(mid %2 ==1){
              e = mid -1;
           }else{
            s = mid +2;
           }
        }else{
            // element found
            return ar[mid];
        }
       mid = (s+e)/2; 
    }
  return 0;  
}

/*
Given a sorted array of N integers, where every element except one appears exactly twice and one element appears only once. Search Single Element in a sorted array.

Example 1:

Input: N = 9, array[] = {1,1,2,3,3,4,4,8,8} 

Output: 2

Explanation: Every element in this sorted array except 2 
appears twice, therefore the answer returned will be 2.
Example 2:

Input: N = 7, array[] = {11,22,22,34,34,57,57} 

Output: 11

Explanation: Every element in this sorted array except 
11 appears twice, therefore the answer returned will be 11.
*/
int main()
{
    vector<int> s = {11,22,22,34,34,57,57} ;
    cout << searchSingleElement(7,s);
}