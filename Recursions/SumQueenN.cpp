#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <map>

using namespace std;



void printBoard(vector<vector<int>>mat,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool canPlace(vector<vector<int>> &board,int n, int i, int k){

    // check col
    int row=i, col =k;
    while (row>=0)
    {
        if(board[row][col] ==1){
            return false;
        }
        row--;
    }
    
    
    // check left diagonal
    row=i, col =k;
    while (row>=0 && col>=0)
    {
        if(board[row][col] == 1){
            return false;
        }

        row--;
        col--;
    }
    
    // right side dia
     row=i, col =k;
     while (row>=0 && col<=n)
    {
        if(board[row][col] == 1){
            return false;
        }

        row--;
        col++;
    }
  return true;
   
}

int sum =0;
bool solveQueen(vector<vector<int>> &board,int n, int i){

 // base case   
 if(i == n){
    printBoard(board,n);
    return true;
 }

// each col in a row
for(int col = 0;col< n ;col++){
   if(canPlace(board,n,i,col)){
    board[i][col]=1;
    bool result = solveQueen(board,n,i+1);
    if(result){
         sum = sum +1;;
    }
    
   board[i][col]=0;
   }
}

return false;
}



int nQueen(int n){
   // base case 
   
return 0;
}

int main()
{
 vector<vector<int>> board(20,vector<int>(20,0)) ;
 solveQueen(board,4,0);
  cout<< "Sum"<<sum;
}