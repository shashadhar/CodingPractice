#include<iostream>
#include<vector>

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
        root->left = createbst(root->left,data);
    }else{
        root->right = createbst(root->right,data);
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

bool isPresent(Node * root, int data){
    if(root==NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }else if(root->data > data){
        return isPresent(root->left,data);
    }else{
        return isPresent(root->right,data);
    }
   return false;
    
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
    if(root->data > target->data){
       successor = root;
       temp = temp->left;

    }else if(root->data < target->data){
        temp = temp->right;
    }else{
        break;
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
    if(isPresent(root, 14)){
        cout<<"Present";
    }else{
        cout<<"not present";
    }

    
    
}