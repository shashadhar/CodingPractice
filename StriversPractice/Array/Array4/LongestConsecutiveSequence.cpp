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


int longestConsecutiveSequece(vector<int> ar){
    unordered_map<int,int> map ;

    for(auto s : ar){
      map[s]++;
    }
 
    int maxLength=0;
    for(auto s: ar){
        int start;
        int count;
        // find the series start no
        if(map.find(s-1)== map.end()){
         // get the series length
         start = s;
         count = 1;
         while (map.find(s+1)!= map.end())
         {
             count = count + 1;
             s = s+1;
         }
        maxLength = max(count, maxLength);
         
        }
    }
 return maxLength;   
}

/*You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

Examples:

Example 1:

Input: [100, 200, 1, 3, 2, 4]

Output: 4

Explanation: The longest consecutive subsequence is 1, 2, 3, and 4. **/
int main(){

 vector<int> ar = {100,200,1,3,2,4}  ;
 cout<< longestConsecutiveSequece(ar); 

    
}
