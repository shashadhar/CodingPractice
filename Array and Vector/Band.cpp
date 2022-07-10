#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr={1,9,3,0,18,5,2,4,10,7,12,6};
    unordered_set<int> elements;
    for(auto s: arr){
        elements.insert(s);
    }
    int maxBand=0;
    for(auto s : arr){
        
        //check start of a band
        if(elements.count(s-1)==0){
            //find the band
            int cnt = 0;
            while(elements.count(s++)!=0){
                cnt++;
            }
         maxBand = max(cnt,maxBand);
        }else {
            // not a start of a band
        }


    }

  cout<<"Max band:"<<maxBand;  
    
}