#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int subsetSum(vector<int>arr,int sum,int index,int n){
    if(n == index){
        if(sum ==0){
        return 1;
        }else {
            return 0;
        }
    }
    int a = subsetSum(arr,sum-arr[index],index+1,n);
    int b = subsetSum(arr,sum,index+1,n);
    return a + b;
}


// subset sum using recursion
int main()
{
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    int sum = 10;
     cout<<subsetSum(arr,sum,0,n);
    
}
