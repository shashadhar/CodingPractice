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

Node* sortedArrayToBST(vector<int> arr, int start, int end) 
{ 
    //Return Null if s > e, because no array elements are there
    if (start > end) 
        return NULL; 
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    Node *root = new Node(arr[mid]); 
  
    //create left & right subtrees recursively
    root->left = sortedArrayToBST(arr, start, mid - 1); 
    root->right = sortedArrayToBST(arr, mid + 1, end); 
 
    return root; 
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