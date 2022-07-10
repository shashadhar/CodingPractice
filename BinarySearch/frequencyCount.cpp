#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


int lowerBound (vector<int> ar , int element,int start , int end){
    int resultLowerBound = -1;
    int mid = (start + end)/2;
    while (end>= start){
        if(ar[mid] == element){
           resultLowerBound = mid;
           end = mid-1;
           }else if(ar[mid] > element){
          end = mid -1;
        }else{
          start = mid +1;
        }
        mid = (start + end)/2;
    }
    return resultLowerBound;
}


int upperBound (vector<int> ar , int element,int start , int end){
    int resultUpperBound = -1;
    int mid = (start + end)/2;
    while (end>= start){
        if(ar[mid] == element){
           resultUpperBound = mid;
           start = mid+1;
           }else if(ar[mid] > element){
          end = mid -1;
        }else{
          start = mid +1;
        }
        mid = (start + end)/2;
    }
    return resultUpperBound;
}

int frequencyCout (vector<int> ar , int element,int start , int end){
    int result = 0;
    int mid = (start + end)/2;
    while (end>= start){
        if(ar[mid] == element){
           int c1 = frequencyCout(ar,element,start,mid-1);
           int c2 = frequencyCout (ar,element,mid+1,end);
           return c1 +c2 +1;
        }else if(ar[mid] > element){
          end = mid -1;
        }else{
          start = mid +1;
        }
        mid = (start + end)/2;
    }
    return result;
}

 int main() {
     vector<int> ar{0,1,1,1,2,2,2,3,4,4,5,10}; 
     int start =0;
     int end = ar.size() -1;
     cout<<(upperBound(ar,2,start,end) - lowerBound(ar,2,start,end)) + 1 <<endl;

     cout << upper_bound (ar.begin(),ar.end(),2) -  lower_bound(ar.begin(),ar.end(),2);
 }