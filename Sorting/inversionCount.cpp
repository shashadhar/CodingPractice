#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int  merge(vector<int>&a1 , int begin,int mid,int end){
    vector<int>merged;
    int i=begin,j=mid+1;
    int cnt =0;
   
    while((i <=mid) && (j <= end)){
        if(a1[i] < a1[j]){
            merged.push_back(a1[i]);
            i++;

        }else{
            cnt += (mid -i) +1;
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
    return cnt;

}

int inversionCount(vector<int> &arr, int start, int end){
   int c=0,d=0,e=0;
    if(start >= end){
       return 0;
   }

   int mid = (start + end)/2;
   c= inversionCount(arr,start, mid);
   d= inversionCount(arr,mid+1,end);
   e = merge(arr,start,mid,end);
   return (c+d+e);
    
}

// replace space with %20
int main()
{
    vector<int>  arr{7,5,2,3,1};
    int s =0;
    int end = arr.size()-1;
    int f = inversionCount(arr,s,end);

    for(auto s : arr){
        cout<<s<<" ";
    }

    cout<<endl<<"Count:"<<f;
     
    
}
