#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Given an array with the nos as the max no of jump it can take
 * Find the minimum no of jump needed to reach the final index
 */

int minJumpRec(vector<int> arr , int n, int i=0){
    if(i==n){
        return 0;
    }

    int minJump=INT_MAX;
    for(int jump =1;jump<=arr[i];jump++){
        if(i+jump<=n){
        minJump = min(minJump,1+minJumpRec(arr,n,i+jump));
        }
    }
    return minJump;
}

int minJumpTD(vector<int> arr , int n, int i,vector<int> &dp){
    if(i==n){
        return 0;
    }

    if(dp[i]!= 0){
        return dp[i];
    }

    int minJump=INT_MAX;
    for(int jump =1;jump<=arr[i];jump++){
        int nextCell = i + jump;
        if(nextCell<=n){
        minJump = min(minJump,1+minJumpTD(arr,n,i+jump,dp));
        }
    }
    return dp[i]=minJump;
}

int main(){
    vector<int> arr= {3,4,2,1,2,3,7,1,1,3};
    int n = arr.size();
    vector<int> dp(n+1,0);
    cout<<"Jump:"<<minJumpTD(arr,n-1,0,dp);
   
}