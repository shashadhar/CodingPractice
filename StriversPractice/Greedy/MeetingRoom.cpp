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

class Meeting{
    public:
    int start;
    int end;
    int pos;
};

bool compare(Meeting m1 , Meeting m2){
    if(m1.end < m2.end){
      return true;
    }
    if(m1.pos < m2.pos){
        return true;
    }
    return false;
}

vector<int> maxMeeting(vector<int> start, vector<int> end){

    vector<int> result;

    // start,end, pos
    vector<Meeting> meetings;
    for(int i=0;i<start.size();i++){
         Meeting m;
         m.start = start[i];
         m.end = end[i];

         // starts from 1
         m.pos = i+1;
         meetings.push_back(m);
    }
    
    sort(meetings.begin(),meetings.end(),compare);

    int limit = 0;
    
    for(auto s : meetings ){
          if(s.start >=limit ){
            result.push_back(s.pos);
            limit = s.end;
          }
    }

return result;
}

/*Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.

Example:

Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}

Output: 1 2 4 5

Explanation: See the figure for a better understanding. 
*/

int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,5,7,9,9};
    vector<int> result = maxMeeting(start,end);
    for(auto s: result){
        cout<< s;
    }
    
}