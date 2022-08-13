#include<iostream>
#include<vector>

using namespace std;

int stockBuyAndSell(vector<int> stocks){

     int n = stocks.size();
     vector<int> right(n,0);
     right[n-1]= stocks[n-1];
     int rightMax = 0;
     int maxProfit = 0;
     for(int i=n-2;i>=0;i--){
         rightMax = max(rightMax,stocks[i+1]);
         maxProfit =  max(maxProfit, rightMax - stocks[i]);
     }
    return maxProfit;
  
}


/**
 * Sort an array of 0's, 1's and 2's
 */
int main(){

    vector<int> arr = {7,6,4,3,1};
    cout<<stockBuyAndSell(arr);
    
}
