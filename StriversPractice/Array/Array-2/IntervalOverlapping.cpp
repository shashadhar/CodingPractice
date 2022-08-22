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

bool compare(vector<int> i1, vector<int> i2){
    return i1[0] < i2[0];
}

vector<vector<int>> overlapArray(vector<vector<int>> arr){

    vector<vector<int>> result;
    // sort on start interval
    sort(arr.begin(),arr.end(), compare);
    int start = arr[0][0];
    int end = arr[0][1];

    for(int i=1; i< arr.size() ; i++){
        // overlapp 
        if(arr[i][0]<= end){
           // check if end interval changing
           if(arr[i][1]> end){
               end = arr[i][1];
           }

        } else{
            // new interval 
            // add the last interval to result
            result.push_back({start,end});
            start = arr[i][0];
            end = arr[i][1]; 
        }

    }

    // insert the last interval
    result.push_back({start,end});
    return result;
}


/**
 * merge all the overlapping intervals and return an array of non-overlapping intervals.
 * Example 1: 

Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
 intervals.

Example 2:

Input: [[1,4],[4,5]]

Output: [[1,5]]

Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].
 */
int main(){
 //vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};

  vector<vector<int>> arr = {{1,4},{4,5}};
vector<vector<int>> result = overlapArray(arr);

for(auto s : result){
     for (auto b: s)
     {
         cout<< b <<" ";
     }
     cout<<endl;
     
}
}



