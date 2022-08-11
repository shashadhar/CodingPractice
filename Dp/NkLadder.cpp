#include <iostream>

using namespace std;

/**
 * Complexity k^n as at each value of n we are doing k calls
 */
int ladderRec(int n, int k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    int ans=0;
    for(int jump=1;jump<=k;jump++){
        ans += ladderRec(n-jump,k);
    }
    
 return ans;

}

int ladder(int n, int k,int dp[]){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }

    int ans=0;
    for(int jump=1;jump<=k;jump++){
        ans += ladder(n-jump,k,dp);
    }
    
    return dp[n]= ans;

}

int main(){
    int dp[1000]={0};
    cout<<"steps"<<ladder(4,3,dp);

}