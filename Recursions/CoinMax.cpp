#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <map>
#include<math.h>
using namespace std;

void maxValueHelper(int n , vector<int> values,int i, int &ows, int &henry)
{
  // base case  
  if(i==n){
    return ; 
  }

  // oswald and henry case
  //oswald takes the first value
  if(i%2 ==0){
  ows = ows + values[i];
  }else{
    henry = henry + values[i];
  }
return  maxValueHelper(n,values,i+1, ows,henry);
}

int maxValue(int n, vector<int> values){
    // sort the values
    sort(values.begin(), values.end(),greater<int>());
    int owsProfit=0, henProfit=0;
    maxValueHelper(n,values,0,owsProfit,henProfit);
return owsProfit;

}

int game(int n, vector<int> v, int s, int e){

    if(s==e || s==e-1){
        return max(v[s],v[e]);
    }

    int op1=v[s] + min(game(n,v,s+2,e),game(n,v,s+1,e-1));
    int op2=v[e] + min(game(n,v,s+1,e-1),game(n,v,s,e-2));
    return max(op1,op2); 
}

int MaxValue(int n, vector<int> v){
    int res=game(n,v,0,n-1);
    return res;
}


/*
Oswald and Henry are playing the game of coins. They have a row of 'n' coins [C1,C2,C3...Cn] with values [V1,V2,V3...Vn] where Ci coin has Vi value. They take turns alternatively. In one turn the player can pick either the first or the last coin of the row. Given both Oswald and Henry are very smart players, you need to find the maximum possible value Oswald can earn if he plays first.

Input Format:

In the function you are given an integer N i.e. the number of coins and a vector V which represents the values of each coin in the row respectively.

Output Format:

Return a single integer which is the maximum possible value as asked in the question.

Constraints:

1<=N<=15

1<=V[i]<=1000

Sample Testcase:

Input:

4

1 2 3 4

Output:

6

Explanation:

Oswald will pick up coin with value 4, Henry will pick coin with value 3, Oswald will pick 2 and Henry will pick 1. Hence 4+2=6.
*/
int main()
{
   vector<int> coins = {1,2,3,4};
   cout<< maxValue(4,coins);
}