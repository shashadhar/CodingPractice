#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;

 int subarray(vector<int> nums){
     int ms = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                int sum = 0;
                for(int k = i; k <= j; k++) {
                    sum += nums[k];
                }
                ms = max(ms, sum);
            }
        }
        
        cout<<"MS:"<<ms;
        return ms;
 }



int main()
{
    vector<int> arr={-1,2,3,4,-2,6,-8,3};
    int n = arr.size();
    //int max = INT_MAX;
    /*int srt,end;
    int ms=0;
    int currentSum=0;
    srt=0;end=0;
    for(int i=0;i<n;i++){
     currentSum = max(arr[i],currentSum+arr[i]); 
     ms = max(ms,currentSum);
    }
    cout<<"Max Sum:"<<ms;*/
    subarray(arr);


    
}