#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Given rod length and price cut for each length , we need to 
 * find the maximum profit we can get by cutting the rod 
 * in available length
 */

int maxProfitRod( vector<int> prices, int n, int dp[]){
    if(n==0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }

   int maxProfit = INT_MIN;
   for(int i =0;i<=prices.size();i++){
       int cut = n - (i+1);
       if(cut>=0 ){
       maxProfit = max(prices[i]+ maxProfitRod(prices, cut,dp),maxProfit);
       }
   }
   return dp[n]=maxProfit;

}


int maxProfitRodBU( vector<int> prices, int n){
    int dp[n+1];
    
    dp[0]=0;

   int maxProfit = INT_MIN;
   for(int len =1;len<= n ;len++){
       for(int i=0;i<len;i++){
           int cut = i+1;
           if((len - cut)>=0 ){
            maxProfit = max((prices[i] + dp[len - cut]),maxProfit);
       }
     }   
     dp[len]= maxProfit;

   }
   return dp[n];

}

int main(){
    vector<int> prices= {3,5,8,9,10,17,17,20};
    int dp[1000]={0};
    cout<<"max profit"<<maxProfitRodBU(prices,8);
   
}