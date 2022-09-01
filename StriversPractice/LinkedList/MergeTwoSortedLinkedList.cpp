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



// Without using extra space
Node* mergeSortedList(Node* head1, Node* head2){
    Node* temp = NULL;

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    
    if(head1->data > head2->data){
       temp = head2;
       temp->next = mergeSortedList(head1, head2->next);
    }else{
       temp = head1;
       temp->next = mergeSortedList(head1->next, head2); 
    } 
    return temp;
  }

/*Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Example 1:

Input Format :
l1 = {3,7,10}, l2 = {1,2,5,8,10}

Output :
{1,2,3,5,7,8,10,10} */
int main(){
    Node* head = new Node(1);
    insertEnd(head,2);
    insertEnd(head,3);
    insertEnd(head,4);
    insertEnd(head,5);
    print(head);
    cout<<endl;
}
