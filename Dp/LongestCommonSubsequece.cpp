#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int LCS (string s1, string s2, int i, int j){
    // base case
    if((i == s1.length()) || (j==s2.length())){
        return 0;
    } 

    if(s1[i] == s2[j]){
        return 1+ LCS(s1,s2,i+1,j+1);
    }else{
        int opt1 = LCS(s1,s2,i+1,j);
        int opt2 = LCS(s1,s2,i,j+1);
        return max(opt1,opt2);
    }
    
}


int LCSTD (string s1, string s2, int i, int j, vector<vector<int>> &dp){
    // base case
    if((i == s1.length()) || (j==s2.length())){
        return 0;
    } 

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s1[i] == s2[j]){
        return dp[i][j] = 1+ LCSTD(s1,s2,i+1,j+1,dp);
    }else{
        int opt1 = LCSTD(s1,s2,i+1,j,dp);
        int opt2 = LCSTD(s1,s2,i,j+1,dp);
        return dp[i][j]=max(opt1,opt2);
    }
    
}

// we need to find the max height achieved so that we can stack 
// one box on top of another when bottom box has more width,depth,height
//{width,depth,height}

int main(){
    string s = "ABCD";
    string s2 = "ABEDG";
    cout<< LCS(s,s2,0,0);
    int n1= s.length();
    int n2 = s2.length();

   vector<vector<int>> dp(n1, vector<int>(n2,-1));
   cout<<endl<< LCSTD(s,s2,0,0,dp);
}