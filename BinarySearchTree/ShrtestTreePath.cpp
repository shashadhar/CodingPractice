#include<iostream>
#include<vector>

using namespace std;


class Node {
    public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
    Node* root = NULL;

    Node(int data){
        this->data = data;
    }
    
};

Node* findParentNodeToInsert(Node* root,int data){

    if(root->data > data){
        if(root->left!=NULL){
           return  findParentNodeToInsert(root->left,data);
        }else{
            return root;
        }

    }else{
       if(root->right!=NULL){
           return  findParentNodeToInsert(root->right,data);
        }else{
            return root;
        }
    }

}

Node* createbst(Node* root, int data){
    if(root==NULL){
     return new Node(data);
    }

    // find the position to insert
    if(root->data > data){
        Node* leftNode = createbst(root->left,data);
        leftNode->root = root;
        root->left =  leftNode;

    }else{
        Node* right = createbst(root->right,data);
        right->root = root;
        root->right= right;
    }
    return root;

}

void inorderTraverse(Node* root){
    if(root == NULL){
        return ;
    }
    inorderTraverse(root->left);
    cout<<root->data<<" ";
    inorderTraverse(root->right);
}

Node* isPresent(Node * root, int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data == data){
        return root;
    }else if(root->data > data){
        return isPresent(root->left,data);
    }else{
        return isPresent(root->right,data);
    }
   return NULL;
    
}
Node* successor;
Node* inorderSuccessor(Node* root, Node* target){

    // check if right node is not null
    if(target->right!=NULL){
        // go to extreme left and get the element
        Node* temp = target->right;
        while (temp!=NULL)
        {
             temp = temp->left;
        }
        return temp;
        
    }

    Node* temp =root;
    Node* successor = NULL;

    while (temp!=NULL)
    {
    
    // we need to traverse till we get the target
    if(temp->data > target->data){
       successor = temp;
       temp = temp->left;

    }else if(temp->data < target->data){
        temp = temp->right;
    }else{
        break;
    }
    }

   return successor;
}


// This is the inorder successor of special case where
// root node is not given, only target node given
Node* inorderSuccessorSpecial(Node* target){

    // check if right node is not null
    if(target->right!=NULL){
        // go to extreme left and get the element
        Node* temp = target->right;
        while (temp->left!=NULL)
        {
             temp = temp->left;
        }
        return temp;
        
    }

    // this is the case where we dont have right sub tree , 
    // now we need to get root node which is greater than the target
    Node* temp =target->root;
    Node* successor = NULL;

    while (temp!=NULL)
    {
    
    // we need to traverse till we get the target
    if(temp->data > target->data){
       successor = temp;
       temp = temp->root;
       break;

    }else if(temp->data < target->data){
        temp = temp->root;
    }else{
        break;
    }
    }

   return successor;
}

Node* LCA(Node* root , int a , int b){
    if(root ==NULL){
        return NULL;
    }

    if(root->data == a || root->data == b){
        return root;
    }

    Node * left = LCA(root->left,a,b);
    Node* right = LCA(root->right,a,b);

    if(left!=NULL && right!= NULL){
        return root;
    }else if(left!=NULL){
        return left;
    }
    return right;

}

// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findPath(Node *root, vector<int> &path, int k)
{
    // base case
    if (root == NULL) return false;
 
    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root->data);
 
    // See if the k is same as root's key
    if (root->data == k)
        return true;
 
    // Check if k is found in left or right sub-tree
    if ( (root->left && findPath(root->left, path, k)) ||
         (root->right && findPath(root->right, path, k)) )
        return true;
 
    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
}
 
// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(Node *root, int n1, int n2)
{
    // to store paths to n1 and n2 from the root
    vector<int> path1, path2;
 
    // Find paths from root to n1 and root to n2. If either n1 or n2
    // is not present, return -1
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
          return -1;
 
    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}

// height of target node from the root
int height(Node* root,int target)
{
    // base case tree is empty
    if (root == NULL)
        return 0;
    if(root->data == target){
        return 0;
    }else if( root->data > target){
        return 1+ height(root->left,target);
    }else{
        return 1+ height(root->right,target);
    }
}

int shortestDist(Node* root, int a ,int b){
    Node* lca = LCA(root,a,b);
    int h1 = height(lca,a);
    int h2 = height(lca,b);
    return h1+h2;
}





int main(){
    int a[] = {8,3,10,1,6,14,47,13};
    Node* root =NULL;
    for(auto s : a){
     root = createbst(root,s);
    }

    inorderTraverse(root);
    cout<<endl;

    Node* node = isPresent(root,10);
    cout<<"Inorder successor of 13:"<<inorderSuccessorSpecial(node)->data;
    cout<<endl;
    cout<<"LCA"<<shortestDist(root,1,3);
    
    
}