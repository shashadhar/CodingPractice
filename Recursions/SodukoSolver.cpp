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


bool canPlace(vector<vector<int>> &board, int i, int j, int n)
{
    // check if row has this value
    for (int col = 0; col < board.size(); col++)
    {
        if (board[i][col] == n)
        {
            return false;
        }
    }

    // check if column has this value
    for (int row = 0; row < board.size(); row++)
    {
        if (board[row][j] == n)
        {
            return false;
        }
    }

    // check if grid has this value
    // get start of the grid
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;
    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (board[sx][sy] == n)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSodokuHelper(vector<vector<int>> &board, int i, int j)
{
    // we came out of whole row ie grid
    if (i == board.size())
    {
        printBoard(board, board.size());
        return true;
    }

    // case 1
    if (j == board[0].size() - 1)
    {
        return solveSodokuHelper(board, i + 1, 0);
    }

    if (!board[i][j] == 0)
    {
        return solveSodokuHelper(board, i, j + 1);
    }   

    for (int n = 1; n <= 9; n++)
    {

        // check if we can placce the no here
        if (canPlace(board, i, j, n))
        {
            board[i][j] = n;
            bool result = solveSodokuHelper(board, i, j + 1);
            if (result)
            {
                return true;
            }

            // false case we are trying next no
        }
    }

     board[i][j] = 0;
    return false;
}

/*
We will solve by recusion , first we will try to place a no
and call solve soduku with this no and if solvable then correct
thus keep on trying
*/

vector<vector<int>> solveSudoku(vector<vector<int>> input)
{
   solveSodokuHelper(input,0,0) ;
   return input;
}

int main()
{

  vector<vector<int>> board={
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
 if(!solveSodokuHelper(board,0,0)){
     cout<<"No soln exists"<<endl;
 }else{
    cout<< "Soln exists";
 }

}