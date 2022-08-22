#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include<unordered_map>
#include <string>

using namespace std;

int countTripletInGPSeries(vector<int> ar, int r){
    unordered_map<int,int> rightFr;
    unordered_map<int,int> leftFr;

    // first store all in the right frequency
    for(auto s: ar) {   
        rightFr[s]++;  
    }

    int total = 0;
    // traverse each and move each no to left from the right and count the frequency
    for (auto s : ar)
    {
       // reduce this no freq from the right
       rightFr[s]--;

       // now find the fr of a/r in left and ar in right
       if(s%r == 0){
           int left = leftFr[s/r];
           int right = rightFr[s*r];
           total = total + left*right;
       }
       leftFr[s]++;

    }
    return total;
}


// Count triplet in GP series
// a/r, a , ar
int main()
{
 vector<int> arr = {1,16,4,16,64,16};
 cout<<countTripletInGPSeries(arr,4);
}