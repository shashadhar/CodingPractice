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

// read each word separated by space
void readEachWord(string s){
    stringstream ss(s);
    string t;
    while(ss >> t){
     cout<<t <<endl;
    }

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


// Diameter of a tere
int diameter(Node* root){
    if(root ==NULL){
        return 0;
    }
    int d1 = height(root->left)+height(root->right)+1;
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
   return max(d1,max(d2,d3));
}
// Diameter of a tere in a optimized way
// dont traverse whole tree for height,take advantage of the diameter traversal
pair<int,int> diameterOptimized (Node* root){
    if(root ==NULL){
        return make_pair(0,0);
    }

    pair left = diameterOptimized(root->left);
    pair right = diameterOptimized(root->right);
    int height = max(left.first,right.first)+1;
   return make_pair(height,max(left.first + right.first +1,max(left.second,right.second)));
}
int replaceWithDecendantSum(Node * root){
    if(root ==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
    return root->data;
    }else{
    int left = replaceWithDecendantSum(root->left);
    int right = replaceWithDecendantSum(root->right);
    int tempdata = root->data;
    root->data = left + right;
    return tempdata + root->data;
    }
}


pair<int,bool> isBalanced(Node * root){
    pair<int ,bool> p,left,right; 
    if(root == NULL){
        // height
        p.first = 0;
        // balanced
        p.second = true;
        return p;
    }
   
   left= isBalanced(root->left);
   right = isBalanced(root->right);
   int height = max(left.first , right.first)+1;
   p.first = height;
   if(left.second && right.second && (abs(left.first - right.first)<=1)){
       p.second = true;
       return p;
   }
   p.second = false;
     return p;
   
}

class Pair
{

public:
    int inc;
    int exc;
};


// max subset sum
Pair maxSubsetSum(Node * root){
    Pair p;
    if(root == NULL){
        p.inc =0;
        p.exc =0;
        return p;
    }
    Pair left = maxSubsetSum(root->left);
    Pair right = maxSubsetSum(root->right);
    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc,left.exc) + max(right.inc,right.exc);
    return p;
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


int main(){
//string ss = "124--57---3-6--";
//Node * root  =  buildTree(ss);
// levelOrderTraverse(root);
// readEachWord("My Name is Shashadhar");

// create tree from level order traversal
string ss ="12345-6--7-----";
Node* rootLevel= buildTreeLevelOrder(ss);
levelOrderTraverse(rootLevel);
cout<<"Diameter:"<<diameter(rootLevel);
cout<<endl;
cout<<"Height:"<<height(rootLevel);
cout<<"OptimizedDiameter:"<<endl;
pair<int,int> t = diameterOptimized(rootLevel);
cout<<max(t.first + 1, t.second);
cout<<endl<<"Replace with descendaant"<<endl;


//replaceWithDecendantSum(rootLevel);
levelOrderTraverse(rootLevel);

if(isBalanced(rootLevel).second){
    cout<<"Balanced!";
}else{
    cout<<"not balanced!";
}
cout<<endl;
Pair p = maxSubsetSum(rootLevel);
cout<<"Max subset sum:"<<max(p.exc,p.inc)<<endl;
printKLevelNodes(rootLevel,3);

}