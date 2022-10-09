#include<bits/stdc++.h>

using namespace  std;

class Node{
  public:  
  int data;
  Node * left;
  Node * right;
};

void leftView(Node* root,int curMax, int level, vector<int> &res){
 if(root == NULL){
  return ;
 }
 if(curMax < level){
  curMax = level;
  res.push_back(root->data);
 }
  // go to left  
  leftView(root->left,curMax, level+1,res);
  // go to right
  leftView(root->left,curMax, level+1,res);

}

vector<int> getLeftView(Node* root){
 vector<int> result;
 leftView(root, INT_MIN, 0,result);
 return result;
  
}


int main(){

}