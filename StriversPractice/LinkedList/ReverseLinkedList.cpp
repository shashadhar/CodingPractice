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
void insert(Node* &head , int data){
      Node* temp = new Node(data);
      temp->next = head;
      head = temp;
    }
void print(Node * head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
} 

Node * reverseHead= NULL;
void reverseLinkedList(Node* head){

    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        reverseHead = head;
    }
    Node * prev = head;
    Node* next = head->next;
    reverseLinkedList(head->next);
    if(next!=NULL){
    next->next = prev;
    }
}

Node* reverseIteratively(Node * head){
    Node* tmp = head;
    if(head == NULL){
        return head ;
    }
    Node* prev = NULL;
    Node* next= NULL;
    while(tmp){
       next = tmp->next;
       tmp->next = prev;
       prev = tmp;
       tmp = next;
    }
   return prev; 
}



int main(){
    Node* head = new Node(5);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);    
    print(head);
    cout<<endl;
    Node* head2 = reverseIteratively(head);
    print(head2);
}
