#include <iostream>
#include <unordered_map>

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
void print(Node<T>* head){
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }      
  }  



// merge two sorted list
template <typename T>
Node<T>* mergeSortedList(Node<T>* head1, Node<T>* head2){
    Node<T>* temp;

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    
    if(head1->data < head2->data){

       temp = head1;
       temp->next = mergeSortedList(head1->next, head2); 
       
    }else{
       temp = head2;
       temp->next = mergeSortedList(head1, head2->next);
    } 
    return temp;
}
   
// get mid node   
template <typename T>
Node<T>* getMidNode(Node<T>* head){
Node <T>* slow=head;
Node <T>* fast= head->next;

while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    
}
return slow;
}

template<typename T>
Node<T>* mergeSort(Node<T>* head){

    if( head == NULL || head->next==NULL){
        return head;
    }

    // calculate mid
    Node<T>* mid = getMidNode(head);
    Node<T>* a = head;
    Node<T>* b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);
    Node <T>* temp = mergeSortedList(a,b);
    //cout<<endl;
    //print(temp);
    //cout<<endl;
    return temp;

}

template<typename T>
bool containsCycle(Node<T> *head){
    //Complete this function 
    
    Node<T>*slow = head;
    Node<T>*fast = head;
    
    while(slow and fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}


template<typename T>
bool checkCycle (Node<T>* head){
    bool result = false;
    unordered_map<Node<T>*,bool> list;
    Node<T>* temp = head;
    while (temp!=NULL)
    {
        if(list.count(temp)!=0){
            return true;
        }else{
            list[temp]=true;
        }
     temp=temp->next;
    }
    return result;
}


int main(){
    Node<int> * head = NULL;
    insert(head,100);
    insert(head,8);
    insert(head,7);
    insert(head,1);
    insert(head,5);
    insert(head,4);
    insert(head,3);
    insert(head,14);


    cout<<"List 1";
    print(head);
    cout<<endl<<"after sort"<<endl;
    head = mergeSort(head);
    print(head);
    
    Node<int> * temp = head;
    while(temp!=NULL){
        if(temp->data ==5){
            temp->next = head;
            break;
            
        }
        temp = temp->next;
    }

    cout<<endl<<checkCycle(head);


    Node<int>* head2 = NULL;
    insert(head2,48);
    insert(head2,47);
    insert(head2,46);
    insert(head2,45);
    cout<<endl<<"List2"<<endl;
    print(head2);
    
    cout<<endl<<"merged list"<<endl;
   // head = mergeSortedList(head,head2);
    //print(head);
    
    

}