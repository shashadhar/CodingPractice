#include <bits/stdc++.h>

using namespace std;
void sortedInsert(stack<int> &stack,int num){
    if(stack.empty() || (stack.top()<num && !stack.empty())){
        stack.push(num);
        return;
    }
    
    int x=stack.top();
    stack.pop();
    sortedInsert(stack,num);
    stack.push(x);
    
    
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty())
        return;
    
    int num=stack.top();
    stack.pop();
    
    sortStack(stack);
    sortedInsert(stack,num);
        
    
}



int main(){
stack<int> st;
st.push(9);
st.push(7);
st.push(1);
st.push(2);
sortStack(st);

}