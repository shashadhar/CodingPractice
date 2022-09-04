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

  template <typename T>
  class LinkedListNode{
        public:
	    T data;
	    LinkedListNode<T>* next;
	    LinkedListNode<T>* random;

	    LinkedListNode(T data) {
		    this->data = data;
	    }
    };


void cloneLinkedList(LinkedListNode<int> * head){
    LinkedListNode<int>* tmp = head;
    LinkedListNode<int>* newhead;
    while(tmp!= NULL){
        // create a new node
        LinkedListNode<int> * newNode = new LinkedListNode<int>(tmp->data);
        newNode->next = tmp->next;
        tmp->next = newNode;
        tmp = newNode->next;
    }

    newhead = head->next;

    // update random pointer
    tmp = head;
    while (tmp!=NULL)
    {
        LinkedListNode<int> * clone = tmp->next;
        clone->random = tmp->random->next;
        tmp = clone->next; 
        
    }
    
    // cloned LL
    tmp = head;
    while(tmp){
        LinkedListNode<int> * clone = tmp->next;
        tmp->next = clone->next;
        if(clone && clone->next){
        clone->next = clone->next->next;
        }
        tmp = tmp->next;
    }


   cout<<endl;
   // print
   while(newhead!=NULL){
       cout<< newhead->data<< " "<< "random:"<< newhead->random->data << " ";
       newhead = newhead->next;
   }
 
}



int main(){
LinkedListNode<int> * head = new LinkedListNode<int>(1);
LinkedListNode<int> * two = new LinkedListNode<int>(2);
LinkedListNode<int> * three = new LinkedListNode<int>(3);
LinkedListNode<int> * four = new LinkedListNode<int>(4);
LinkedListNode<int> * five = new LinkedListNode<int>(5);
head->next = two;
head->random = three;

two->next = three;
two->random = head;

three->next = four;
three->random = five;

four->next = five;
four->random = five;

five->next = NULL;
five->random = two;

cloneLinkedList(head);

}