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

int subArrayWithSumK(vector<int> arr,int k){
unordered_map<int,int> prevSum;
int currentSum=0;
int result=0;
for(int i=0;i<arr.size();i++){
    currentSum = currentSum + arr[i];
    if(currentSum == k){
        result++;
    }else if(prevSum.count(currentSum - k)!=0){
          result = result + prevSum[currentSum -k];
    }
    prevSum[currentSum]++;
}
return result;
}


int main()
{
   vector<int> arr = {10, 2, -2, -20, 10};
   cout<<subArrayWithSumK(arr,-10);
    
}