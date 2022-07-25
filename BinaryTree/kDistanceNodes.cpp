#include <iostream>
#include <queue>
#include<sstream>
#include<utility>
#include <algorithm>
using namespace std;

class Node {
    public:
    int data;
    Node* left=NULL;
    Node* right=NULL;

    Node(int data){
        this->data = data;
    }
    
};


Node* buildTree(string ss){
static int i =-1;
i =i+1;
if(ss[i]=='-'){
    return NULL;
}

Node * temp = new Node(ss[i]-'0');

temp->left = buildTree(ss);
temp->right = buildTree(ss);

return temp;

}

Node* buildTreeLevelOrder(string ss){
    queue<Node*> que; 
    int i =0;
    Node * root = new Node(ss[i]-'0');
    que.push(root);

    while(!que.empty()){
        Node* popedNode = que.front();
        que.pop();
        // get the next two nodes
        char leftData = ss[++i];
        char rightData = ss[++i];
        if(leftData!='-'){
             Node * left = new Node(leftData- '0');
             popedNode->left = left;
             que.push(left);
        }else{
          popedNode->left = NULL;
        }
        if(rightData!='-'){
          Node * right = new Node (rightData-'0');
             popedNode->right = right;
             que.push(right);
        }else{
             popedNode->right = NULL;
        }
    }
    return root;
}

int height(Node* node)
{
    // base case tree is empty
    if (node == NULL)
        return 0;
 
    // If tree is not empty then height = 1 + max of left
    // height and right heights
    return 1 + max(height(node->left), height(node->right));
}

void levelOrderTraverse(Node * root){
    queue<Node *> que;
    que.push(root);
    que.push(NULL);
    while (!que.empty())
    {
        Node * popedNode = que.front();
        que.pop();

        // this for level wise print , new line
        if(popedNode == NULL){
          cout<<endl;
          if(!que.empty()){
          que.push(NULL);
          }
        }else{

        cout<<popedNode->data<<" ";
        if(popedNode->left!= NULL){
           que.push(popedNode->left);
        }
        if(popedNode->right!=NULL){
            que.push(popedNode->right);
        }
        }

    }
    

}

void storeKLevelNodes(Node* root, int level,vector<int> &nodes){
    if(root == NULL){
        return;
    }
    if(level==0){
        //cout<<root->data<<" ";
        nodes.push_back(root->data);
        return;
    }

    level = level -1;
    storeKLevelNodes(root->left,level,nodes);
    storeKLevelNodes(root->right,level,nodes);
    return;

}


void printKLevelNodes(Node* root, int level){
    if(root == NULL){
        return;
    }
    if(level==0){
        cout<<root->data<<" ";
        return;
    }

    level = level -1;
    printKLevelNodes(root->left,level);
    printKLevelNodes(root->right,level);
    return;

}


// k distance node , sorted 
int kDistanceNodeSorted(Node* root,int target,int k,vector<int>&nodes){
    if(root == NULL){
        return -1;
    }
  if(root->data == target){
      storeKLevelNodes(root,k,nodes);
      return 0;
  }

  // we found the target node in left sub tress
  int DL = kDistanceNodeSorted(root->left,target,k,nodes);
  if(DL!=-1){
   
   // we have found the target node in left substree
   // 2 cases , 1) right tree distance 2) parent itself
  if(DL+1 == k){
      //cout<< root->data;
      nodes.push_back(root->data);
  }else{
      storeKLevelNodes(root->right,k-DL-2,nodes);
  }
  return 1+DL;
  }

  // we found the target node in right sub tress
  int DR = kDistanceNodeSorted(root->right,target,k,nodes);
  if(DR!=-1){
   
   // we have found the target node in left substree
   // 2 cases , 1) right tree distance 2) parent itself
  if(DR+1 == k){
      //cout<< root->data;
      nodes.push_back(root->data);
  }else{
      storeKLevelNodes(root->left,k-DR-2,nodes);
  }
  return 1+DR;  
  }
  return -1;  
}




// k distance node
int kDistanceNode(Node* root,int target,int k){
    if(root == NULL){
        return -1;
    }
  if(root->data == target){
      printKLevelNodes(root,k);
      return 0;
  }

  // we found the target node in left sub tress
  int DL = kDistanceNode(root->left,target,k);
  if(DL!=-1){
   
   // we have found the target node in left substree
   // 2 cases , 1) right tree distance 2) parent itself
  if(DL+1 == k){
      cout<< root->data;
  }else{
      printKLevelNodes(root->right,k-DL-2);
  }
  return 1+DL;
  }

  // we found the target node in right sub tress
  int DR = kDistanceNode(root->right,target,k);
  if(DR!=-1){
   
   // we have found the target node in left substree
   // 2 cases , 1) right tree distance 2) parent itself
  if(DR+1 == k){
      cout<< root->data;
  }else{
      printKLevelNodes(root->left,k-DR-2);
  }
  return 1+DR;  
  }
  return -1;  
}


int main(){
//string ss = "124--57---3-6--";
//Node * root  =  buildTree(ss);
// levelOrderTraverse(root);


// create tree from level order traversal
string ss ="12345-6--7-----";
Node* rootLevel= buildTreeLevelOrder(ss);
levelOrderTraverse(rootLevel);
kDistanceNode(rootLevel,2,2);

cout<<endl;
vector <int> result;
kDistanceNodeSorted(rootLevel,2,2,result);
sort(result.begin(),result.end());
for(auto s: result){
    cout<<s<<" ";
}

}