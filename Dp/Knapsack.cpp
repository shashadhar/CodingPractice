#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


int knapsackDp(int wts[],int prices[],int N, int W){
    vector<vector<int>> dp (N+1,vector<int>(W+1,0)) ;
    for (int n  = 1; n <= N; n++)
    {
        for ( int w = 1; w <=W; w++)
        {
            int inc=0, exc =0;
            if(wts[n-1]<=w){
                inc = prices[n-1] + dp[n-1][ w-wts[n-1]];
            }
            exc = dp[n-1][w];
            dp[n][w]= max(inc,exc);
        }
        
    }
   return dp[N][W]; 

}

int knapsackRec(int wts[], int prices[],int n , int w){
if(n<=0 || w<=0){
    return 0;
}

int inc=0,exl=0;
if(wts[n-1]<=w){
inc = prices[n-1] + knapsackRec(wts,prices,n-1,w-wts[n-1]);
}
exl = knapsackRec(wts,prices,n-1,w);
return max(exl,inc);

}


int main(){
    int wts[] = {2,7,3,4};
    int prices[] ={5,20,20,10};
     
     int n =4;
     int w = 11;
     cout<<knapsackRec(wts,prices,n,w);
     cout<< knapsackDp(wts,prices,n,w);


}