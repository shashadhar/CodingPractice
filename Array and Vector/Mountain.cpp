#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
     int mountain=0;
    // get the peek index
    for(int i = 1; i<arr.size()-1;){
        if(arr.at(i-1)<arr.at(i) && arr.at(i+1)<arr.at(i)){
            int cnt = 1;
            int j = i;
            // cnt backward
            while (j>=1 and arr[j]>arr[j-1]){
                cnt++;
                j--;
            }

            //cnt forward
            while(i<arr.size()-1 && arr[i]>arr[i+1]){
                cnt++;
                i++;
            }
            mountain = max(mountain,cnt);  
    
        }else{
            i++;
        }

       
      
}
 cout<<"Mountain:"<<mountain;
}