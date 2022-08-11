#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Given an array, we need to longest increasing sequence
 * BU approach
 */
int list(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,1);
    int len =1;
    for(int i =1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                dp[i]= max(dp[i],1+dp[j]);
                len = max(len, dp[i]);
            }
        }
    }
    return len;
}

int LIS(vector<int> arr,int n){
    if(n == 0){
        return 1;
    }
    int ans = 1;
    for (int i = n - 1; i>=0; i--){
    if (arr[i] < arr[n]){
      ans = max(ans, 1 + LIS(arr, i));
    }
    }
    return ans;
}

int lisRec(vector<int> arr, int n){
  int max_ans = 1;
  for (int i = 0;i<n;i++){
    max_ans = max(max_ans, LIS(arr, i));
  }
  return max_ans;
}

int main(){
    vector<int> arr= {6,10,12,7,9,14};
    int n = arr.size();
    vector<int> dp(n+1,0);
    cout<<"LIS:"<<lisRec(arr,n);
    cout<<endl<<list(arr);
   
}