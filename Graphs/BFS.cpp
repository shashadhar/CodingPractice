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

  void BFS(int startNode){
      queue<int> nodeQueue;
      vector<bool> visited(100,false);
      nodeQueue.push(startNode);
      visited[startNode] = true;
      while(!nodeQueue.empty()){
       int node = nodeQueue.front();
       nodeQueue.pop();
        cout<< node << " ";

        // push all the neighbour of node to queue
        for(auto s : adj[node]){
            if(!visited[s]){
                nodeQueue.push(s);
                visited[s]=true;
            }
        }
      } 
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
  g.BFS(1);
}
