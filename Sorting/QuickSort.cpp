#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>&a1 , int begin,int end){
    int pivot = a1[begin];
    int i=begin; int j=end;

     while(i<j) {
         do {
             i++;
         } while(a1[i]<=pivot);

         do {
             j--;
         } while(a1[j]>pivot);

         if(i<j) {
             swap(a1[i],a1[j]);
         }
     }

     swap(a1[begin], a1[j]);

     return j;
}

// last element as pivot
int partition3(vector<int> &a,int s, int l){
    int pivot = a[l];
    int i =s-1;
    int j =s;
    for(;j<l;j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1],pivot);
}


int partition2 ( vector<int> &A,int start ,int end) {
    int i = start + 1;
    int piv = A[start] ;            //make the first element as pivot element.
    for(int j =start + 1; j <= end ; j++ )  {
    /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */

          if ( A[ j ] < piv) {
                 swap (A[ i ],A [ j ]);
            i += 1;
        }
   }
   swap ( A[ start ] ,A[ i-1 ] ) ;  //put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}

void quick_sort(vector<int> &A, int start, int end){
     if( start < end ) {
        //stores the position of pivot element
         int piv_pos = partition2 (A,start , end ) ;     
         quick_sort (A,start , piv_pos -1);    //sorts the left side of pivot.
         quick_sort ( A,piv_pos +1 , end) ; //sorts the right side of pivot.
   }
     
}

// replace space with %20
int main()
{
    vector<int>  arr{0,4,2,7,6,4};
   
     quick_sort(arr,0,arr.size()-1);
     for(auto s: arr){
         cout<<s<<" ";
     }
    
}
