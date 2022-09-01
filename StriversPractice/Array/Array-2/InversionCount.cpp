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
int merge(vector<int> &ar, int s1, int e1, int s2, int e2){
    vector<int> merged;
    int i = s1;
    int j = s2;
    int total =0;

    while (i<=e1 && j<=e2)
    {
        if(ar[i] < ar[j]){
        merged.push_back(ar[i++]);     
        }else{
            // we got i which is a[i] > a[j], since this i greater mean all other i upto e1 also grater
            // it is a sorted so pair is all i , j
            total = total + (e1-i) +1;
            merged.push_back(ar[j++]);
        }
    }

    while (i<=e1)
    {
       merged.push_back(ar[i++]); 
    }

    while (j<=e2)
    {
        merged.push_back(ar[j++]);
    }
    
    // copy back all the elements to ar
    int k=0;
    for(int i =s1; i<= e2 ; i++){
        ar[i]= merged[k++];
    }
    return total;

}


int mergeSort(vector<int> &ar, int s, int e){
    while(s < e){
        int mid = (s+e)/2;
        int inv =  mergeSort(ar,s,mid);
        inv +=  mergeSort(ar,mid+1,e);
        inv += merge(ar, s,mid,mid+1,e);
        return inv;
    }
    return 0 ;
}
/**
 * 
Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Example 1:

Input Format: N = 5, array[] = {1,2,3,4,5}

Result: 0

Explanation: we have a sorted array and the sorted array 
has 0 inversions as for i < j you will never find a pair 
such that A[j] < A[i]. More clear example: 2 has index 1 
and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an 
inversion.
Example 2:

Input Format: N = 5, array[] = {5,4,3,2,1}

Result: 10

Explanation: we have a reverse sorted array and we will 
get the maximum inversions as for i < j we will always 
find a pair such that A[j] < A[i]. 
Example: 5 has index 0 and 3 has index 2 now (5,3) pair 
is inversion as 0 < 2 and 5 > 3 which will satisfy out 
conditions and for reverse sorted array we will get 
maximum inversions and that is (n)*(n-1) / 2.

For above given array there is 4 + 3 + 2 + 1 = 10 inversions.
Example 3:

Input Format: N = 5, array[] = {5,3,2,1,4}

Result: 7

Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),
(3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and 
(1,4) as both are not satisfy our condition. 
 * 
 */

int main(){
 vector<int> ar ={5,3,2,1,4};
  cout << mergeSort(ar,0, 4);
  
}
