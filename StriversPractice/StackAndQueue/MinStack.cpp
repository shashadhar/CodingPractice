#include<bits/stdc++.h>

using namespace std;


/*
Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Examples:

Input Format:["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
[
[ ], [-2], [0], [-3], [ ], [ ], [ ], [ ]
]

Result: [null, null, null, null, -3, null, 0, -2]
Explanation: 
stack < long long > st
st.push(-2); Push element in stack
st.push(0); Push element in stack
st.push(-3); Push element in stack
st.getMin(); Get minimum element fromstack
st.pop(); Pop the topmost element
st.top(); Top element is 0
st.getMin(); Minimum element is -2
*/

stack<pair<int, int>> myStack;

void push(int ele)
{
   pair<int, int> ins = {ele, ele};
   if (!myStack.empty())
   {

      auto top = myStack.top();
      if (top.second < ele)
      {
         ins.second = top.second;
      }
   }
   myStack.push(ins);
}

int getMin()
{
   return myStack.top().second;
}

void pop()
{
   myStack.pop();
}

int main()
{
   push(4);
   push(6);
   cout << getMin() << endl;
}