#include <iostream>

using namespace std;

template <typename T>
class Node
{
private:
    /* data */
public:

    T data;
    Node<T> * next;
    Node(T data){
        this->data = data;
    }
};

template <typename T>
void insert(Node<T>* &head , T data){
      Node<T>* temp = new Node<T>(data);
      temp->next = head;
      head = temp;
    }

template <typename T>
void insertMiddle(Node<T> * &head, T data,int pos){

    if(pos == 0 ){
        insert(head,data);
    }


    Node<T> * tempHead = head;
    // get the position to insert
    for(int i=0;i<pos-1;i++){
        tempHead = tempHead -> next;
    }

    Node<T> * tempNew = new Node<T>(data);
    tempNew ->next = tempHead->next;
    tempHead ->next = tempNew;



}    

template <typename T>
Node<T>* reverse(Node<T>* start){
    if(start == NULL || start->next == NULL){
        return start;
    }
    
    Node<T> * shead = reverse(start->next);
    start->next->next=start;
    start->next = NULL;
    return shead;  

}

template <typename T>
void reverseIteratively2(Node<T>* &start){
    Node<T>* prev = NULL;
    Node<T>* current= start;
    Node<T>* temp;

    while(current!=NULL){
        temp = current->next;
        current->next = prev;
        prev = current;
        current= temp;
    }

    start = prev;

}



template <typename T>
Node<T>* reverseIteratively(Node<T>* start){
    Node<T>* prev = NULL;
    Node<T>* next = NULL;

    while(start!=NULL){
        next = start->next;
        start->next = prev;
        prev = start;
        start = next;
    }

    return prev;

}



  template <typename T>
  void print(Node<T>* head){
      while (head!=NULL)
      {
          cout<<head->data<<"->";
          head = head->next;
      }
      

  }  

  template <typename T>
  Node<T>* kReverseLinkedList(Node<T>* head, int k){
    Node<T>* prev = NULL;
    Node<T>* current= head;
    Node<T>* temp;
    int cnt=0;

    if(head == NULL || head->next == NULL){
        return head;
    }

    while(current!=NULL && cnt<k){
        temp = current->next;
        current->next = prev;
        prev = current;
        current= temp;
        cnt++;
    }

    if(current!=NULL){
        head ->next = kReverseLinkedList(current,k);
    }

    return prev;
  }

int main(){
    Node<int> * head = NULL;
    insert(head,7);
    insert(head,8);
    insert(head,10);
    insert(head,100);
    cout<<"Insert at head";
    print(head);
    cout<<endl<<"After inserting at midle"<<endl;
    insertMiddle(head,112,3);
    print(head);
    
    cout<<"Revers"<<endl;
    //head = reverse(head);
    //head = reverseIteratively(head);
    //reverseIteratively2(head);
    //print(head);

    head = kReverseLinkedList(head,3);
    print(head);

}