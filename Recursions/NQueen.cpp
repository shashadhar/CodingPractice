#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

bool canPlace(int board[][20],int i,int j,int n){

    // check if the same column has any queeen placed
    for(int k =0; k<i;k++){
        if(board[k][j]==1){
            return false;
        }
    }
    
    // check diagonal left
    int row=i; int col = j;
    while((row>=0 && row<n) && (col>=0 && col<n)){
        if(board[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    // check diagonal right
     row=i; col = j;
    while((row>=0 && row<n) && (col>=0 && col<n)){
        if(board[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    return true;

}

void printBoard(int board[][20],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


bool solveQueen(int board[][20],int i,int n){

    // if we have placed all rows then return
    if(i==n){
        printBoard(board,n);
        return true;
    }

    // we will place queen in the
    // ith row and jth column, check if it is a feasible solution
    for(int j=0;j<n;j++){
        if(canPlace(board,i,j,n)){
            board[i][j] = 1;
            bool success = solveQueen(board,i+1,n);
            if(success){
                return true;
            }
          // backtrack
          board[i][j]=0;
        }
    }
    return false;
}

// N queeen problem , place a queen so that no other queen should be placed to
// the same row, same column and diagonally
int main()
{
 int board[20][20]={0};
 int n;
 cout<<"Enter value of n:";
 cin>>n;
 solveQueen(board,0,n);
  
}
