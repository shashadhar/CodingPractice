#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


bool isPossible(vector<int> coins , int n,int k, int leastCoin){
  bool result = false;
   int allocate =0;
   int allocated = 0;
   for(auto s : coins){
      allocate = allocate + s;
     if (allocate>=leastCoin){
         allocate = 0;
        allocated = allocated + 1;
     }
   }

   if(allocated >=k){
     result = true;
   }

  return result;
}


int partition(vector<int> coins,int n,int k){
  int s = 0;
  int e =0;
  int result=0;
  for(auto s : coins){
    e = e+s;
  }

  int mid = (s+e)/2;
 
 while(e>=s){
    if(isPossible(coins,n,k,mid)){
      result = mid;
      s = mid +1;
    }else{
      e = mid -1;
    }
    mid = (s+e)/2;
 }

return result;
}


// we are given with coins and need to partition such a way that everyone gets 
// atleast max amout of coins
 int main() {
   vector<int> coins {1,2,3,4};
   int n = coins.size();
   int k = 3;
   cout << "Max partition value"<< partition(coins,n,k);

    
 }