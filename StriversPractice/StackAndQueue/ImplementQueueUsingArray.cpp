#include <bits/stdc++.h>

using namespace std;

class Que
{

private:
    int f = -1;
    int r = -1;
    vector<int> contents;

    bool isEmpty()
    {
        if (r == -1 && f == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {

        if ((f == 0 && r == size - 1) || (f == r + 1))
        {
            return true;
        }

        return false;
    }

public:
    int size;

    Que(int s)
    {
        size = s;
        contents = vector<int>(size, -1);
        f = -1;
        r = -1;
    }

    int top()
    {
      // Function to display status of Circular Queue
    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      cout << "Front -> " << f;
      cout << contents[f]<<endl;
    }

    }

    int pop()
    {
        int element;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return (-1);
        }
        else
        {
            element = contents[f];
            if (f == r)
            {
                f = -1;
                r = -1;
            }
            // Q has only one element,
            // so we reset the queue after deleting it.
            else
            {
                f = (f + 1) % size;
            }
            return (element);
        }
    }

    void enqueue(int el)
    {
        if (isFull())
        {
            cout << "Queue is full";
        }
        else
        {
            if (f == -1)
                f = 0;
            r = (r + 1) % size;
            contents[r] = el;
            cout << endl
                 << "Inserted " << el << endl;
        }
    }
};

int main()
{

    Que s(3);
    s.enqueue(3);
    s.enqueue(6);
    s.enqueue(7);

    s.top();
    s.pop();
    s.top();
}