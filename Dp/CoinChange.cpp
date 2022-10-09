#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

/**
 * 
 * Given coins and a target , we need to find the minimum no of coin needed to get the target
 * 
 */

int getCoin(vector<int> coins,int target){
    if(target == 0){
        return 0;
    }
    int minCoin = INT_MAX;
    for(auto coin: coins){
        if(target - coin >= 0){
        int c1 = 1 + getCoin(coins,target - coin);
        minCoin =  min(minCoin,c1);
        }
    }
    return minCoin;
}

int getCoinTP(vector<int> coins, int target, vector<int>&dp){
    if(target ==0){
        return 0;
    }

    if(dp[target]!= INT_MAX){
        return dp[target];
    }

    int minCoin = INT_MAX;
    for(auto coin: coins){
        if(target - coin >= 0){
        int c1 = 1 + getCoinTP(coins,target - coin,dp);
        minCoin =  min(minCoin,c1);
        }
    }
    return dp[target] = minCoin;
}

int getCoinBU(vector<int> coins, int target){
    vector<int> dp(target+1,0);

    dp[0]=0;

    for(int i=1; i<=target; i++){
        dp[i]=INT_MAX;
        for (auto coin:coins)
        {
            if((i - coin) >= 0 & dp[i-coin] != INT_MAX){
                dp[i]=min(dp[i],dp[i-coin]+1);
                 
            }
        }
        
    }



}


int main(){
    vector<int> denoms= {1,5,7,10};
    vector<int> dp(1000,INT_MAX);
    cout<<"coins:"<<getCoinTP(denoms,16,dp)<<endl;
    cout<< getCoin(denoms,16);

}