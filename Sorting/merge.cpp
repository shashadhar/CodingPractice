#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>&a1 , int begin,int mid,int end){
    vector<int>merged;
    int i=begin,j=mid+1;
    while((i <=mid) && (j <= end)){
        if(a1[i]<a1[j]){
            merged.push_back(a1[i]);
            i++;

        }else{
            merged.push_back(a1[j]);
            j++;
        }
    }

    while(i <=mid){
       merged.push_back(a1[i]);
       i++;
    }
    while(j <= end){
        merged.push_back(a1[j]);
        j++;
    }

    // copy elements back to original array
    int k=0;
    for(int id =begin;id<=end;id++){
        a1[id]=merged[k++];
    }
    

}

void mergeSort(vector<int> &arr, int start, int end){
   
   /* if(s >= e){
       return;
   }*/

    if(start <end){
   int mid = start + (end-start)/2;
   mergeSort(arr,start, mid);
   mergeSort(arr,mid+1,end);
   merge(arr,start,mid,end);
    }
}

// replace space with %20
int main()
{
    vector<int>  arr{0,4,2,7,6,4};
    int s =0;
    int end = arr.size()-1;
    mergeSort(arr,s,end);

    for(auto s : arr){
        cout<<s<<" ";
    }
     
    
}
