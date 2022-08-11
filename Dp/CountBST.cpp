#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int countBST(int n){
    if(n==0 || n==1){
        return 1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
    int n1 = countBST(i-1);
    int n2 = countBST(n-i);
    ans = ans + (n1*n2);
    }

   return ans; 
}


int countBSTTD(int n, int dp[]){
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n]!= 0){
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
    int n1 = countBSTTD(i-1,dp);
    int n2 = countBSTTD(n-i,dp);
    ans = ans + (n1*n2);
    }

   return dp[n]=ans; 
}



// we need to cout bst using the formula 
// for all nodes as root (i-1)*(n-i)
int main(){
 cout<<"BST:"<<countBST(3)<<endl;
 int dp[100]={0};
 cout<<"BST TD:"<<countBSTTD(3,dp)<<endl;
}