#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

bool calPath(int n, vector<vector<char>> c , vector<int>&v,int i =0 , int j=0){
    // base condition , we reached the last cell
    if(i==n && j == n){
        return true;
    }

    if(i == n+1 || j == n+1 ) {
        return false;
    }

    // right direction
    if(j!=n && c[i][j+1]!='X'){
         if(calPath(n,c,v,i,j+1)){
            v.push_back(i*(n+1) + j+2);
            return true;
         }
    }

    // down direction
    if(i!=n && c[i+1][j]!='X'){
         if(calPath(n,c,v,i+1,j)){
            v.push_back((i+1)*(n+1) + j+1);
            return true;
         }
    }
    return false;
}

vector<int> findPath(int n, vector<vector<char>> c){
   vector<int> v;
    calPath(n-1,c,v);
    v.push_back(1);
    reverse(v.begin(), v.end());
    return v;
    
}


int main()
{
  vector<int> result;
  vector<vector<char>> c ={
    {'O','O','X'},
    {'O','X','X'},
    {'O','O','O'}
  };

  result = findPath(3,c);
  for(auto s : result){
    cout << s<< " ";
  }
  
}
