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


Node* kReverseLinkList(Node* head , int k){
        if (head==NULL)
        {
            return NULL;
        }

        Node* temp = head;
        Node* prev = NULL;
        Node* next = NULL;
        int cnt =0;
        while(temp!= NULL && cnt < k){
           next  = temp->next;
           temp->next = prev;
           prev = temp;
           temp = next;
           cnt++;
        }

        if(temp != NULL){
            head->next = kReverseLinkList(temp,k);
        }

       return prev;
}



/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Examples:

Example 1:
Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:
2
Explanation: Here, both lists intersecting nodes start from node 2.

Example 2:
Input:
 List1 = [1,2,7], List 2 = [2,8,1]
Output:
 Null

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
    Node* temp = head1->next->next->next;
    
    Node* head2 = new Node(3);
    head2->next = temp;
    cout<<endl;
    print(head2);
    cout<<endl;
    Node* head = kReverseLinkList(head1,3);
    print(head);


}
