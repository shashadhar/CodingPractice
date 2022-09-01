#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <map>
#include<list>
#include<stack>

using namespace std;


class Graph
{

public:
  int v;
  list<int> *adj;

  Graph(int vertices){
    v = vertices;
    adj = new list<int>[v];
  }  

  void addEdge(int src, int dest, bool undir = true){
      adj[src].push_back(dest);
      if(undir){
         adj[dest].push_back(src);
      }
  }

  void printAdjList(){
      for(int i=0; i< v;i++){
          cout<< i << "-->";
          // all element of ith list
          for(auto s : adj[i]){
              cout<< s << " ";
          }
          cout<<endl;
      }
  }

  bool checkeCycle(int startNode){
      stack<int> stackQueue;
      vector<bool> visited(100,false);
      int *parent = new int[v]; 

      stackQueue.push(startNode);
      visited[startNode] = true;
      for(int i =0;i < v;i++){
        parent[i] = -1;
      }

      parent[startNode] = startNode;

      while(!stackQueue.empty()){
       int node = stackQueue.top();
       stackQueue.pop();
        cout<< node << " ";

        // push all the neighbour of node to queue
        for(auto s : adj[node]){
            if(!visited[s]){
                stackQueue.push(s);
                visited[s]=true;
                parent[s] = node;
            }else if(visited[s] && parent[node]!=s ){
              return true;
            }
        }
      } 
  return false;    
  }


    
};





int main(){
  Graph g (6);
  g.addEdge(0,1);
  g.addEdge(0,4);
  g.addEdge(2,1);
  g.addEdge(3,4);
  g.addEdge(4,5);
  g.addEdge(2,3);
  g.addEdge(3,5);

  g.printAdjList();
  cout<< g.checkeCycle(1);
}
