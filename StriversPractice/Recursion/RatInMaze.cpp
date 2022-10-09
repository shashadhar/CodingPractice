#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

void calPath(int n, vector<vector<int>> c , string move,vector<vector<int>> &visited , vector<string> &result, int i =0 , int j=0){
    // base condition , we reached the last cell
    if(i==n-1 && j == n-1){
        result.push_back(move);
        return;
    }

     // down direction
    if(i+1<n && c[i+1][j]!=0 && visited[i+1][j]!=1){
      visited[i][j] =1 ;
      calPath(n,c,move+'D',visited,result,i+1,j);
      visited[i][j] =0 ;
    }

    // left direction
    if(j-1>=0 && c[i][j-1]!=0 && visited[i][j-1]!=1){
      visited[i][j] =1 ;
         calPath(n,c,move + 'L',visited,result,i,j-1);
           visited[i][j] =0 ;
    }

    // right direction
    if(j+1<n && c[i][j+1]!=0 && visited[i][j+1]!=1){
      visited[i][j]= 1;
      calPath(n,c,move + 'R',visited,result,i,j+1);
      visited[i][j]= 0;

    }
    
     // up direction
    if(i-1 >=0 && c[i-1][j]!=0 && visited[i-1][j]!=1){
      visited[i][j] =1;
         calPath(n,c,move + 'U',visited,result,i-1,j);
         visited[i][j] =0;
    }
    return ;
}

void findPath(int n, vector<vector<int>> c){
   string v="";
   vector<vector<int>> visited(n,vector<int>(n,0));
   vector<string> result;
  calPath(n,c,v,visited,result);
    //reverse(v.begin(), v.end());

    for(auto s : result){
      cout<< s;
      cout<<endl;
    }
    
}

/*
Rat in a Maze

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

Note: In a path, no cell can be visited more than one time.

Print the answer in lexicographical(sorted) order

Examples:

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}}

Output: DDRDRR DRDDRR

*/

int main()
{
  vector<char> result;
  vector<vector<int>> c ={{1, 0, 0, 0},
                          {1, 1, 0, 1}, 
                          {1, 1, 0, 0},
                          {0, 1, 1, 1}
                          };

  findPath(4,c);
    
}
