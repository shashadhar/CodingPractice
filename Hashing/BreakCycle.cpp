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

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
    }
};

node *breakChain(node *head)
{
    //Complete this method
    unordered_map<node *, bool> nodes;
    node *temp = head;
    node *prev = NULL;
    while (temp != NULL)
    {
        // we found the node
        if (nodes[temp] == true)
        {
            prev->next = NULL;
            break;
        }
        else
        {
            nodes[temp] = true;
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

/**
 * Given a link list which contains a cycle 
 * break the cycle using hash and point to null
 * in the last node
 * 
 */
int main()
{
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n2;

    node *head = breakChain(n1);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}