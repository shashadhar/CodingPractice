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

   // we will count for each i , how many j elements are available such a[i] > a[j] *2

   for(int k = s1; k <= e1; k++){
       int m = s2; 
       while( m <= e2 &&  ar[k] > 2 * ar[m] ){
          m++;
       }
       total = total + (m- s2);
   }


    while (i<=e1 && j<=e2)
    {
        if(ar[i] < ar[j]){
        merged.push_back(ar[i++]);     
        }else{
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
 * Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

Examples:

Example 1:

Input: N = 5, array[] = {1,3,2,3,1)

Output: 2 

Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

Example 2:

Input: N = 4, array[] = {3,2,1,4}

Output: 1

Explaination: There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]
 * 
 * 
 */

int main(){
 vector<int> ar ={3,2,1,4};
  cout << mergeSort(ar,0, 3 );
  
}
