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


//process as per mentioned in solution
Node* detectCycle(Node* head) {
    if(head == NULL||head->next == NULL) return NULL;
        
    Node* fast = head;
    Node* slow = head;
    Node* entry = head;
        
    while(fast->next != NULL&&fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow == fast) {
            while(slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}






/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that the tail’s next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Examples:

Example 1:
Input:
 head = [1,2,3,4,3,6,10]
Output:
 tail connects to node index 2 i.e 3
Explanation:

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
    print(head2);
}
