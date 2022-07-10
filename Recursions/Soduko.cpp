#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

bool isSafe(int mat[][9],int i,int j,int no,int n){
    
    // check if we have same no in the row and column
   for(int col=0;col<n;col++ ){
       if(mat[i][col]==no || mat[col][j]==no){
             return false;
            }
    }

    // check the subgrid
    // get the first cell of the subgrid
    int sx = (i/3)*3;
    int sy = (j/3)*3;
    for(int x = sx;x<sx+3;x++){
        for(int y=sy;y<sy+3;y++){
            if(mat[x][y]==no){
                return false;
            }
        }
    }

return true;

}

void printBoard(int mat[][9],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


bool solveSoduko(int mat[][9],int i,int j,int n){

    // if we have placed all rows then return
    if(i==n){
        printBoard(mat,n);
        return true;
    }

    // corner case when we reach end of a row
    if(j==n){
      return  solveSoduko(mat,i+1,0,n) ;
    }
   
   // skip the filled cell
   if(mat[i][j]!=0){
       return solveSoduko(mat,i,j+1,n);
   }

   // now try all the possible nos
   for(int no = 1; no<=n; no++){
       if(isSafe(mat,i,j,no,n)){
           mat[i][j]=no;
           bool possible = solveSoduko(mat,i,j+1,n);
           if(possible){
               return true;
           }

       }
   }

   mat[i][j]=0;
   return false;
}

// Soduko game, place a number so that it solve the entire grid and no number
// repeated in the same row, same column and the sub grid
int main()
{
  int n=9;
  int mat[9][9]={
      {5,3,0,0,7,0,0,0,0},
      {6,0,0,1,9,5,0,0,0},
      {0,9,8,0,0,0,0,6,0},
      {8,0,0,0,6,0,0,0,3},
      {4,0,0,8,0,3,0,0,1},
      {7,0,0,0,2,0,0,0,6},
      {0,6,0,0,0,0,2,8,0},
      {0,0,0,4,1,9,0,0,5},
      {0,0,0,0,8,0,0,7,9}
  };
 if(!solveSoduko(mat,0,0,9)){
     cout<<"No soln exists"<<endl;
 }
  
}
