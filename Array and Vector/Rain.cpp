#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
    int n = arr.size();
    int waterTrapped=0;
    if(n<=2){
     return waterTrapped;
    }else{
        vector<int> right(n,0),left(n,0);
        // now for each element we should fill left highest and right highest
        left[0]=arr[0];
        right[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            left[i]= max(left[i-1],arr[i]);
            right[n-i-1]= max(right[n-i],arr[n-i-1]);
            
        }

        for(int i=0;i<=n;i++){
            waterTrapped = waterTrapped + (abs(min(left[i],right[i])-arr[i]));
        }
        cout<<"Water trapped:"<<waterTrapped;
    }
}