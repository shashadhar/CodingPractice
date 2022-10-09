#include<bits/stdc++.h>

using namespace  std;

class Node{
  public:  
  int data;
  Node * left;
  Node * right;
};

void morisInorder(Node* root){
  vector<int> inorder;

  Node* cur = root;

  while (cur!=NULL)
  {
    if(cur->left==NULL){
        inorder.push_back(cur->data);
        cur = cur->right;
    }else{

        Node* prev = cur->left;
        while (prev->right!= NULL && prev->right!= cur){
          prev = prev->right;
        }

        if(prev->right ==NULL){
          prev->right = cur;
          inorder.push_back(cur->data);
          cur = cur->left;
        }else{
           prev->right = NULL;  
           cur = cur->right;
        }
    
    }
    
  }
  

}


int main(){

}