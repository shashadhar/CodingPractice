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

        // started going to right, lets print the root ie cur
        cur = cur->right;
    }else{

        Node* prev = cur->left;
        while (prev->right!= NULL && prev->right!= cur){
          prev = prev->right;
        }

        if(prev->right ==NULL){
          prev->right = cur;
          // going left
          cur = cur->left;
        }else{
           prev->right = NULL;  
           inorder.push_back(cur->data);

           // going right, we are done with left so print the root before going to right
           cur = cur->right;
        }
    
    }
    
  }
  

}


int main(){

}