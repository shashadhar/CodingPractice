#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <map>

using namespace std;

class Node
{
private:
    /* data */
public:

    int data;
    Node * next = NULL;
    Node(int data){
        this->data = data;
    }
};

// inserts at beginning
void insertEnd(Node* &head , int data){
    Node* tmp = head;
    while (tmp->next!=NULL)
    {
        tmp= tmp->next;
    }
    Node * newN = new Node(data);
    tmp->next = newN;
}

void print(Node * head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
} 


// Rotates a node to the right
Node* rotateRight(Node* head){
Node* tmp = head;

// get the last node
Node* prev;
while (tmp->next!=NULL)
{
    prev = tmp;
   tmp = tmp->next; 
}

prev->next = NULL;
tmp->next = head; 
return tmp;
}

Node* rotateLinkedList(Node* head , int k){
 for(int i = 0 ; i< k; i++){
    head = rotateRight(head);
 }
 return head;
}
     

// Rotate by slow and fast pointer
 Node* rotateLinkedListRight(Node* head , int k){
  // slow and fast pointer
  Node* slow = head;
  Node * fast = head;
  for(int i=0;i<k;i++){
    fast = fast->next;
  }

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next;
  }
  
  Node* tmp = slow->next;
  slow->next = NULL;
  fast->next = head;
  head = tmp;


 return head;
} 


//utility function to rotate list by k times
// this one when k is 200000 or more than the length
Node* rotateRight(Node* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    //calculating length
    Node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    //link last node to first node
    temp->next = head;


    k = k%length; //when k is more than length of list
    
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;
}



/*
GIn this article, we will solve the problem: “Rotate a Linked List”

Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

Examples:

Example 1:
Input:
	head = [1,2,3,4,5] 
	k = 2
Output:
 head = [4,5,1,2,3]
Explanation:
 We have to rotate the list to the right twice.
*/

int main(){
    Node* head1 = new Node(1);
    insertEnd(head1,2);
    insertEnd(head1,3);
    insertEnd(head1,4);
    insertEnd(head1,5);
    insertEnd(head1,6);
    insertEnd(head1,7);
    insertEnd(head1,8);
    print(head1);
    cout<<endl;
  
    // node 2
    Node * head = rotateLinkedListRight(head1,2);
    print(head);
    cout<<endl;
 
}
