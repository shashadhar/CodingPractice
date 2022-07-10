#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


int rotatedSearch (vector<int> ar , int key,int start , int end){
    int resultindex = -1;
    int mid = (start + end)/2;
    while (end>= start){
        if(ar[mid] == key){
           return mid;

        // 1st line   
        }else if(ar[start]<=ar[mid]){

          if(ar[start] <= ar[mid] && key <= ar[mid]){
            end = mid -1;
          }else {
            start= mid +1;
          }

        // 2nd line
        }else if (ar[end] >= ar[mid]){
          if(ar[end] >= key && key >= ar[mid]){
            start = mid +1;
          }else{
             end = mid -1;
          }
        }
          
        mid = (start + end)/2;
    }
    return resultindex;
}




 int main() {
     vector<int> ar{4,5,6,7,0,1,2,3}; 
     int start =0;
     int end = ar.size() -1;
     cout<<rotatedSearch(ar,5,start,end);
 }