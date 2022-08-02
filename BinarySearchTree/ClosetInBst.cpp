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

/**
 * Finds the closet node to the target
 * 
 * @return int 
 */
int closetElement;
void findClosestNode(Node* root , int target, int minDiff){
    if(root == NULL){
        return ;
    }
    if(root->data == target){
        closetElement = root->data;
        return;
    }

    // go to right so that difference is minimized
    int diff = abs(root->data - target);
    if(diff < minDiff){
        minDiff = diff;
        closetElement = root->data;
    }

    if(root->data < target ){
        findClosestNode(root->right,target,minDiff);

    }else {
        findClosestNode(root->left,target,minDiff);
    }

 return;

}

int findClosestIteratively(Node* root , int target){
    if(root == NULL){
        return -1;
    }

    int currentDiff;
    int minDiff = INT_MAX;
    int closetElement;
    Node * temp = root;

    while (temp!=NULL)
    {
       if(root->data == target){
           closetElement = temp->data;
           return closetElement;
       }

        currentDiff = abs(temp->data - target);
        if(currentDiff < minDiff){
            minDiff = currentDiff;
            closetElement = temp->data;
        }

       if(temp->data < target){
           //minimize the diff
           temp = temp->right;
       }else{
           temp = temp->left;
       }
    }
   return closetElement; 
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

    findClosestNode(root,5,INT_MAX);
    cout<<"close"<<closetElement;
    cout<<endl;
    cout<<findClosestIteratively(root,5);
    
}