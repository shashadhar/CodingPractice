#include<iostream>
#include <string>
#include<stack>

using namespace std;

bool isBalanced(string exp){
    stack<char> bracketStack;
    for(auto s : exp){
       switch (s)
       {
       case '(':
       case '{':
       case '[':
           bracketStack.push(s);
           break;


       case ')':
            if(!bracketStack.empty() &&  bracketStack.top()=='('){      
             bracketStack.pop();
            }else{
                return false;
            }
            break;
       case '}':
       if(!bracketStack.empty() && bracketStack.top()=='{'){      
             bracketStack.pop();
            }else{
                return false;
            }
            break;
       case ']':
       if(!bracketStack.empty() && bracketStack.top()=='['){      
             bracketStack.pop();
            } else{
                return false;
            }
       break;

       default:
           break;
       } 
    }

 return bracketStack.empty() == 1;  
}

int main(){
    string exp = "(a+b+c)+[d)]";
    cout<<isBalanced(exp);
    


}

