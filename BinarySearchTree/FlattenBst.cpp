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


/* check if BST
// this program is wrong and it fails 
//for the following tree

     3
 2       7
    4
 */   
bool isBst(Node* root){

    if(root == NULL){
        return true;
    }
    if(root->left!=NULL && root->data < root->left->data){
        return false;
    }

    if(root->right!=NULL  && root->data > root->right->data){
        return false;
    }

    if(!isBst(root->left) || !isBst(root->right)){
        return false;
    }
    
    return true;
}


bool isBinarySearchTree(Node* root , int min, int max){
    if(root == NULL){
        return true;
    }

    if(!((root->data > max) || (root->data < min)) ){
        return false;
    }

    return isBinarySearchTree(root->left,min,root->data) && isBinarySearchTree(root->right,root->data,max);
}


class linkList{
    public:
    Node * head=NULL;
    Node* tail=NULL;
};



/**
 * This function creates a new node
 * for the link list
 * @param root 
 * @return linkList* 
 */
linkList* flattenBinarySearchTree(Node* root){
    
    if(root == NULL){
      return NULL;
    }
    linkList* result = new linkList();
    linkList* LH = flattenBinarySearchTree(root->left);
    linkList* RH = flattenBinarySearchTree(root->right);
    
    if(LH ==NULL && RH ==NULL){
      result = new linkList();
      result->head = root;
      result->tail = root;
    }
    if(LH!=NULL && RH ==NULL){
        result->tail = root;
        LH->tail->right = root;
        result->head = LH->head;
    }
    if(LH ==NULL && RH!=NULL){
        result->head = root;
        root->right = RH->head;
        result->tail = RH->tail;
    }
    if(LH!=NULL && RH!=NULL){
     result->head = LH->head;
     LH->tail->right = root;
     root->right = RH->head;
     result->tail = RH->tail;
    }

return result;
}


linkList FlattBst(Node* root){
    linkList res;
    if(root ==NULL){
        res.head = NULL;
        res.head = NULL;
        return res;

    }
    if(root->left==NULL && root->right==NULL){
        res.head = root;
        res.tail = root;
        return res;
    }else if(root->left!=NULL && root->right==NULL){
         linkList leftL=  FlattBst(root->left);
         leftL.tail->right = root;

         res.head = leftL.head;
         res.tail = root;
         return res;
    } else if(root->left == NULL && root->right!=NULL){
        linkList rightL=  FlattBst(root->right);
         root->right = rightL.head;

         res.head = root;
         res.tail = rightL.tail;
         return res;
    }else if(root->left != NULL && root->right!=NULL){
        linkList rightL=  FlattBst(root->right);
        linkList leftL=  FlattBst(root->left);
         root->right = rightL.head;
         leftL.tail->right = root;

         res.head = leftL.head;
         res.tail = rightL.tail;
         return res;
    }

return res;


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

    cout<<endl;
    if(isBinarySearchTree(root,INT_MIN,INT_MAX)){
        cout<<"BST";
    }else{
        cout<<"Not BST";
    }

    cout<<endl;
    linkList result = FlattBst(root);
    Node* tmp = result.head;
    for(;tmp!=NULL;tmp=tmp->right){
        cout<<tmp->data;
    }
    
}