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

void removeNodeAtNth(Node* &head, int pos){
    if(head ==NULL){
        return ;
    }
    Node* slow = head;
    Node* fast = head;
    Node* prev = head;

    // go to the nth node
    for(int i = 1;i<pos;i++){
        if(fast!=NULL){
        fast= fast->next;
        }
    }

    while (fast && fast->next)
    {  
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // delete the slow
    prev->next= slow->next;

}


/*Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.

Example 1 : 

Input: head = [1,2,3,4,5], n = 2

Output: [1,2,3,5] */
int main(){
    Node* head = new Node(1);
    insertEnd(head,2);
    insertEnd(head,3);
    insertEnd(head,4);
    insertEnd(head,5);
    print(head);
    removeNodeAtNth(head, 3);
    cout<<endl;
    print(head);
}
