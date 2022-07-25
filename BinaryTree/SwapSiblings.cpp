#include <iostream>
#include <queue>
#include<sstream>
#include<utility>
#include <algorithm>
#include<map>
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

void verticalOrderPrint(Node* root,int level,map<int,vector<int>> &nodes){
    if(root ==NULL){
        return;
    }    
   nodes[level].push_back(root->data);
    verticalOrderPrint(root->left,level-1,nodes);
    verticalOrderPrint(root->right,level+1,nodes);
    return;  
}

void swapSiblings(Node* root){
    if(root == NULL){
        return;
    }

   Node* temp = root->left;
   root->left = root->right;
   root->right = temp;
   swapSiblings(root->left);
   swapSiblings(root->right);
   return;
}




int main(){
//string ss ="12345-6--7-----";
string ss ="123-4--5---";
Node* rootLevel= buildTreeLevelOrder(ss);
levelOrderTraverse(rootLevel);

map<int,vector<int>> nodes;
verticalOrderPrint(rootLevel,0,nodes);
cout<<endl;
for(auto s : nodes){
   for(auto ss : s.second){
       cout<<ss<<" ";
   }
   cout<<endl;
}
cout<<endl;



}