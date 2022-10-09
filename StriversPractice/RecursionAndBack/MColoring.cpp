#include<bits/stdc++.h>
using namespace std;


class graph{
  
  public:
  int edges[100][100];
  int nodes;

  graph(int n){
    nodes = n;
  }
  void addEdge(int src, int dest){
   edges[src][dest] = 1;
   edges[dest][src] = 1;
  }

  bool isSafe(int node , int col , int color[]){
    for(int k =0;k< nodes;k++){
       if(k!= node && edges[k][node] ==1 && color[k] == col){
           return false;
       }
    }
    return true;
  }



  bool tryColoring(int node , int color[], int noOfColr){
    if(node == nodes){
      return true;
    }
      for(int i =1;i<=noOfColr;i++){

        if(isSafe(node, i , color)){
          color[node] = i;
          if(tryColoring(node+1, color, noOfColr)){
            return true;
          }
          color[i]=0;
        }
    }

 return false;


  }

  bool isColorPossible(int col){
    int color[nodes] ={0};
    return tryColoring(0,color,col);
  }
  
};


/*
Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

Examples:

Example 1:
Input: 
N = 4
M = 3
E = 5
Edges[] = {
  (0, 1),
  (1, 2),
  (2, 3),
  (3, 0),
  (0, 2)
}

Output: 1

Explanation: It is possible to colour the given graph using 3 colours.

Example 2:

Input: 
N = 3
M = 2
E = 3
Edges[] = {
  (0, 1),
  (1, 2),
  (0, 2)
}

Output: 0


Explanation: It is not possible to color.
*/

int main(){

  graph g(3);

  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(0,2);
  //g.addEdge(3,0);
  //g.addEdge(0,2);
  
  cout<< "Possible:" << g.isColorPossible(2);
 
}