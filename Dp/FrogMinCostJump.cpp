#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Given an array with the nos as the cost of jump in this index
 * the cost of jump is abs(indexCost - jumpedIndexCost)
 * Find the minimum cost needed to reach the last index
 */

int minJumpFrogRec(vector<int> arr , int n, int i=0){
    if(i==n-1){
        return 0;
    }

    int minJump=INT_MAX;
    int opt1=INT_MAX,opt2=INT_MAX;
    // two options only either step+1 or step+2
    if(i+1<=n-1){
     opt1 = abs(arr[i] - arr[i+1]) + minJumpFrogRec(arr,n,i+1);
    }
    if(i+2<=n-1){
     opt2 = abs (arr[i]- arr[i+2]) + minJumpFrogRec(arr,n,i+2);
    }
    minJump = min(opt1,opt2);
    return minJump;
    
}

int minJumpTD(vector<int> arr , int n, int i,vector<int> &dp){
    if(i==n-1){
        return 0;
    }

    if(dp[i]!=INT_MAX){
        return dp[i];
    }
    
    int minJump=INT_MAX;
    int opt1=INT_MAX,opt2=INT_MAX;
    // two options only either step+1 or step+2
    if(i+1<=n-1){
     opt1 = abs(arr[i] - arr[i+1]) + minJumpTD(arr,n,i+1,dp);
    }
    if(i+2<=n-1){
     opt2 = abs (arr[i]- arr[i+2]) + minJumpTD(arr,n,i+2,dp);
    }
    minJump = min(opt1,opt2);
    return dp[i]=minJump;
    
}

int main(){
    vector<int> arr= {30,10,60,10,60,50};
    int n = arr.size();
    vector<int> dp(n+1,INT_MAX);
    cout<<"Jump:"<<minJumpTD(arr,n,0,dp);
   
}