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
    
    
}