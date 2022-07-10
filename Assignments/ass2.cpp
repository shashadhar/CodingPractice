#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iomanip>
#include <iostream>
using namespace std;



// node for the circular linked list
// represent a node
struct node
{
    int length;
    int info;
    struct node *n;
    struct node *p;
};

// Class represents the circular linked list
// reponsible for creating a node and inserting a node
class CircularLinkedList
{
public:
    node *start;
    node *last;
    int count = 0;

    // crates a node
    node *create_node(int value, int length)
    {
        count++;
        struct node *t;
        t = new (struct node);
        t->info = value;
        t->length = length;
        t->n = NULL;
        t->p = NULL;
        return t;
    }

    // inserts a node at the beginning of the list
    void insert_begin(int value, int len)
    {

        struct node *temp;
        temp = create_node(value, len);
        if (start == last && start == NULL)
        {
            cout << "Element inserted in empty list" << endl;
            start = last = temp;
            start->n = last->n = NULL;
            start->p = last->p = NULL;
        }
        else
        {
            temp->n = start;
            start->p = temp;
            start = temp;
            start->p = last;
            last->n = start;
            cout << "Element inserted" << endl;
        }
    }

    // inserts a node at the end of the list
    void insert_end(int value, int len)
    {
        int v;
        struct node *temp;
        temp = create_node(value, len);
        if (start == last && start == NULL)
        {
           // cout << "Element inserted in empty list" << endl;
            start = last = temp;
            start->n = last->n = NULL;
            start->p = last->p = NULL;
        }
        else
        {
            last->n = temp;
            temp->p = last;
            last = temp;
            start->p = last;
            last->n = start;
        }
        start->info = count - 1;
        start->length = start->length + len;
    }

    // display the linked list
    void display()
    {
        int i;
        struct node *s;
        if (start == last && start == NULL)
        {
            cout << "The List is empty, nothing to display" << endl;
            return;
        }
        s = start;
        for (i = 0; i < count - 1; i++)
        {
            cout << s->info << ":" << s->length << "<->";
            s = s->n;
        }
        cout << s->info << ":" << s->length << endl;
    }

    int totalDigits()
    {
        return start->length;
    }

    // 1 if fist is larger
    // 0 if first is smaller
    // -1 if same
    int compare(CircularLinkedList *second)
    {
        if (totalDigits() > second->totalDigits())
        {
            return 1;
        }
        else if (totalDigits() < second->totalDigits())
        {
            return 0;
        }
        else
        {
            // have same no of digits compare the nodes value of each list
            node *temp = last;
            node *temp1 = second->last;
            for (int i = 0; i < count - 1; i++)
            {
                if (temp->info > temp1->info)
                {
                    return 1;
                }
                else if (temp->info < temp1->info)
                {
                    return 0;
                }
                else
                {
                }
                temp = temp->p;
                temp1 = temp1->p;
            }
            return -1;
        }

        return -1;
    }

    // Constructor for circular linked list
    CircularLinkedList()
    {
        start = NULL;
        last = NULL;
        insert_end(0, 0);
    }
};

// stores all the lines , read from the file
std::string lines[2];

// representation of nos in linked list
CircularLinkedList *firstNumber = new CircularLinkedList();
CircularLinkedList *secondNumber = new CircularLinkedList();

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

// tokenize the line string to the linked list representation
bool tokenizeAndCreateList(string line, CircularLinkedList *numberRepresentation)
{
    bool validInput = true;
    int from = line.length();
    int to = line.length();
    string str;
    int len;
    // 1324 21978 49762
    while (from > 0)
    {
        to = from;
        from = from - 5;
        if (from < 0)
        {
            len = to - 0;
            str = line.substr(0, to);
        }
        else
        {
            len = to - from;
            str = line.substr(from, to - from);
        }
        // cout << str << endl;
        // cout<<"lenght:"<<len<<endl;
        int num;
        try
        {
            if (isNumber(str))
            {
                //converts string value to interger
                num = std::stoi(str);
            }
            else
            {
                cout << "Not A Proper Input String \n";
                validInput = false;
                break;
            }
        }
        catch (const std::exception &e)
        {
            // we got exception converting to int , mean it is not a valid integer value
            cout << "Not A Proper Input String \n";
            validInput = false;
            break;
        }

        numberRepresentation->insert_end(num, len);
    }
    return validInput;
}

void printList(CircularLinkedList *number,ofstream* file){
        int i;
        struct node *s;
        if (number->start == number->last && number->start == NULL)
        {
            cout << "The List is empty, nothing to display" << endl;
            *file << "The List is empty, nothing to display" << endl;
            return;
        }
        s = number->last;
        for (i = 0; i < number->count - 2; i++)
        {
            cout << std::setfill('0') << std::setw(s->length) << s->info<<",";
            *file << std::setfill('0') << std::setw(s->length) << s->info<<",";
            //cout << s->info << ",";
            s = s->p;
        }
         cout << std::setfill('0') << std::setw(s->length) << s->info<<endl;
         *file << std::setfill('0') << std::setw(s->length) << s->info<<endl;
}


void perfromAddition(CircularLinkedList *firstNumber, CircularLinkedList *secondNumber, ofstream* myfile )
{
    CircularLinkedList *result = new CircularLinkedList();
    node *temp = firstNumber->start->n;
    node *temp1 = secondNumber->start->n;
    int carry = 0, sum;
    while (temp != firstNumber->start || temp1 != secondNumber->start)
    {
        if (temp != firstNumber->start && temp1 != secondNumber->start)
        {
            sum = (temp->info + temp1->info + carry) % 100000;
            carry = (temp->info + temp1->info + carry) / 100000;
            temp = temp->n;
            temp1 = temp1->n;
        }
        else if (temp == firstNumber->start && temp1 != secondNumber->start)
        {
            sum = (temp1->info + carry) % 100000;
            carry = (temp1->info + carry) / 100000;
            temp1 = temp1->n;
        }
        else if (temp != firstNumber->start && temp1 == secondNumber->start)
        {

            sum = (temp->info + carry) % 100000;
            carry = (temp->info + carry) / 100000;
            temp = temp->n;
        }
        result->insert_end(sum, 0);
    }
    printList(result,myfile);
}


// The main function
int main()
{
    int lineCount = 0;
    std::ifstream file("ip.txt");
    if (file.is_open())
    {
        std::string line;
        // just take the first 2 lines and ignore others
        while (std::getline(file, line) && lineCount < 2)
        {
            lines[lineCount++] = line;
        }
        file.close();
    }
    if (lineCount < 2)
    {
        cout << "Only one number entered!";
        return 1;
    }

    if (!tokenizeAndCreateList(lines[0], firstNumber))
    {
        return 1;
    }
    if (!tokenizeAndCreateList(lines[1], secondNumber))
    {
        return 1;
    }

    // create the ouput file
  ofstream myfile;
  myfile.open ("op.txt");
  

    //firstNumber->display();
    //secondNumber->display();
    cout<<"N01:";
    myfile<<"N01:";
    printList(firstNumber,&myfile);
    cout<<endl;
    myfile<<endl;

    cout<<"N02:";
    myfile<<"N02:";
    printList(secondNumber,&myfile);
    cout<<endl;
    myfile<<endl;
    
    int compare = firstNumber->compare(secondNumber);
    if (compare == 1)
    {
        cout << "First number is bigger than the second number" << endl;
        myfile << "First number is bigger than the second number" << endl;
    }
    else if (compare == 0)
    {
        cout << "The second number is bigger than the first number" << endl;
         myfile << "The second number is bigger than the first number" << endl;
    }
    else
    {
        cout << "The numbers are equal" << endl;
         myfile << "The numbers are equal" << endl;
    }
    cout<<"Sum:";
    myfile<<"Sum:";
    perfromAddition(firstNumber, secondNumber,&myfile);

    return 1;
}
