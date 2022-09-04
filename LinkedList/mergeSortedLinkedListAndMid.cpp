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


template <typename T>
Node<T>* mergeSortedList(Node<T>* head1, Node<T>* head2){
    Node<T>* temp = NULL;

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

template <typename T>
Node<T>* kthlastNode(Node<T>* head, int k){
    Node<T>* slow=head;
    Node<T>* fast = head;
   
    for(int i =1;i<k;i++){
        fast = fast->next;
    }

    while (fast && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
    

   

}


template <typename T>
Node<T>* getMidNode(Node<T>* head){
Node <T>* slow=head;
Node <T>* fast= head;

while(fast->next!=NULL && fast->next->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    
}
return slow;
}

int main(){
    Node<int> * head = NULL;
    insert(head,8);
    insert(head,7);
    insert(head,6);
    insert(head,5);
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    cout<<"List 1";
    print(head);

    /*Node<int>* head2 = NULL;
    insert(head2,48);
    insert(head2,47);
    insert(head2,46);
    insert(head2,45);
    cout<<endl<<"List2"<<endl;
    print(head2);
    cout<<endl<<"mid1"<<getMidNode(head)->data<<endl;
    cout<<endl<<"mid2"<<getMidNode(head2)->data<<endl;
    
    cout<<endl<<"merged list"<<endl;
    head = mergeSortedList(head,head2);

    cout<<endl<<"Kth last element"<<endl;
    cout<<kthlastNode(head,3)->data<<endl;*/
    
    cout<< endl;
    head = kReverseLinkedList(head,3);

    print(head);


    
    

}