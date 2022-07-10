//C++ program to insert an element into binary tree
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

// tree node
struct Node
{
	int data;
	Node *left, *right;
};

// returns a new tree Node
Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// A function to create binary tree.
Node* Tree(Node* temp, int data )
{
    // If the tree is empty, return a new node
    if (temp == NULL)
        return newNode(data);

    // Otherwise, recur down the tree
    if (data < temp->data)
        temp->left = Tree(temp->left, data);
    else
        temp->right = Tree(temp->right, data);

    //return the (unchanged) node pointer
    return temp;
}

//function to display all the element present in the binary tree
void display(struct Node* root)
{

    if (!root)
    return;
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);

}

//function to insert element in binary tree
void insert(struct Node* root , int value)
{
    queue<struct Node*> q;
    q.push(root);

    // Do level order traversal until we find an empty place.
    while (!q.empty()) {
        struct Node* root = q.front();
        q.pop();

        if (!root->left) {
            root->left = newNode(value);
            break;
        } else
            q.push(root->left);

        if (!root->right) {
            root->right = newNode(value);
            break;
        } else
            q.push(root->right);
    }
}

// Function to print all nodes of a
// binary tree in Preorder, Postorder
// and Inorder using only one stack
void allTraversal(Node* root, ofstream& op)
{
    // Stores preorder traversal
    vector<int> pre;

    // Stores inorder traversal
    vector<int> post;

    // Stores postorder traversal
    vector<int> in;

    // Stores the nodes and the order
    // in which they are currently visited
    stack<pair<Node*, int> > s;

    // Push root node of the tree
    // into the stack
    s.push(make_pair(root, 1));

    // Traverse the stack while
    // the stack is not empty
    while (!s.empty()) {

        // Stores the top
        // element of the stack
        pair<Node*, int> p = s.top();

        // If the status of top node
        // of the stack is 1
        if (p.second == 1) {

            // Update the status
            // of top node
            s.top().second++;

            // Insert the current node
            // into preorder, pre[]
            pre.push_back(p.first->data);

            // If left child is not NULL
            if (p.first->left) {

                // Insert the left subtree
                // with status code 1
                s.push(make_pair(
                    p.first->left, 1));
            }
        }

        // If the status of top node
        // of the stack is 2
        else if (p.second == 2) {

            // Update the status
            // of top node
            s.top().second++;

            // Insert the current node
            // in inorder, in[]
            in.push_back(p.first->data);

            // If right child is not NULL
            if (p.first->right) {

                // Insert the right subtree into
                // the stack with status code 1
                s.push(make_pair(
                    p.first->right, 1));
            }
        }

        // If the status of top node
        // of the stack is 3
        else {

            // Push the current node
            // in post[]
            post.push_back(p.first->data);

            // Pop the top node
            s.pop();
        }
    }

    cout << "Preorder Traversal: ";
    op << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++) {
        cout << pre[i] << " ";
        op << pre[i] << " ";
    }
    cout << "\n";
    op << "\n";

    // Printing Inorder
    cout << "Inorder Traversal: ";
    op << "Inorder Traversal: ";

    for (int i = 0; i < in.size(); i++) {
        cout << in[i] << " ";
        op << in[i] << " ";
    }
    cout << "\n";
    op << "\n";

    // Printing Postorder
    cout << "Postorder Traversal: ";
    op << "Postorder Traversal: ";

    for (int i = 0; i < post.size(); i++) {
        cout << post[i] << " ";
        op << post[i] << " ";
    }
    cout << "\n";
    op << "\n";
}

int tree_height(Node* root) {
    // Get the height of the tree
    if (root==NULL){
        return 0;
    }
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}
void tilted(struct Node* node)
{
	if(node==NULL)
		return;
	int Lheight = tree_height(node->left);
	int Rheight = tree_height(node->right);
	if(Rheight>Lheight)
	{
		struct Node *t;
		t=node->left;
		node->left=node->right;
		node->right=t;
	}
	tilted(node->left);
	tilted(node->right);
}
		
int main()
{
	char ch;
	int i, j;
	int arr[50][3];
	int arr_size = 0, spaces = 0;
	Node *root = new Node;
	root = NULL;
	

	vector<string> lines;
    string line, dummy;

	ifstream ip("ip.txt");

	while(getline(ip, line)){
        lines.push_back(line);
    }

    ip.close();
    ofstream op("op.txt");

    j = 0;

    for(auto& ls:lines)
    {
        dummy = "";
        spaces = 0;
        for(i=0;i<ls.length();i++)
        {
            if(ls.at(i)==' '){
                if(spaces==0)
                {
                    arr[j][0]=stoi(dummy);
                }
                if(spaces==1)
                {
                    arr[j][1]=stoi(dummy);
                }
                dummy="";
                spaces+=1;
            }
            else
            {
                dummy+=ls.at(i);
            }
        }
        if(spaces==2)
        {
            arr[j][2]=stoi(dummy);
        }
        j++;
    }

	arr_size = j;

	// Construct the binary tree.
	for(i=0;i<arr_size;i++)
	{
	    root = Tree(root, arr[i][0]);
	}

	allTraversal(root, op);
	tilted(root);
    allTraversal(root, op);
	op.close();

	return 0;
}
