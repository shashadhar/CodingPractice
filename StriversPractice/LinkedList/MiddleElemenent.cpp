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

Node* midElement(Node * head){
    if(head ==NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
   return slow; 
}



int main(){
    Node* head = new Node(5);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);    
    insert(head, 6);  
    insert(head, 7);  
    print(head);
    cout<<endl;
    cout<<"Middle element";
    cout<<midElement(head)->data;
}
