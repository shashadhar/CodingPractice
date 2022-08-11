#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Given an array, we need to find max non adjacent sum
 */
int maxNonAdacentSumRec(vector<int> arr , int n, int i=0){
    if(i>n-1){
        return 0;
    }

    int maxSum=0;
    int opt1=0,opt2=0;
    // two options either include arr[i] or exclude arr[i]
     opt1 = arr[i] + maxNonAdacentSumRec(arr,n,i+2);
     opt2 = maxNonAdacentSumRec(arr,n,i+1);
    maxSum = max(opt1,opt2);
    return maxSum;
    
}

/**
 * Given an array, we need to find max non adjacent sum
 */
int maxNonAdacentSumTD(vector<int> arr , int n, int i, vector<int> dp){
    if(i>n-1){
        return 0;
    }
    if(dp[i]!=0){
        return dp[i];
    }
    int maxSum=0;
    int opt1=0,opt2=0;
    // two options either include arr[i] or exclude arr[i]
     opt1 = arr[i] + maxNonAdacentSumTD(arr,n,i+2,dp);
     opt2 = maxNonAdacentSumTD(arr,n,i+1,dp);
    maxSum = max(opt1,opt2);
    return dp[i]=maxSum;
    
}

/**
 * Given an array, we need to find max non adjacent sum
 */
int maxNonAdacentSumBU(vector<int> arr , int n){
    vector dp(n,0);
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    
    int maxSum=0;
    int opt1=0,opt2=0;
    for(int i =2;i<n;i++){
    // two options either include arr[i] or exclude arr[i]
    opt1 = arr[i] + dp[i-2];
    opt2 = dp[i-1];
    maxSum = max(opt1,opt2);
    dp[i]=maxSum;
    }

    return dp[n-1];
    
}

int main(){
    vector<int> arr= {6,10,12,7,9,14};
    int n = arr.size();
    vector<int> dp(n+1,0);
    cout<<"Jump:"<<maxNonAdacentSumBU(arr,n);
   
}