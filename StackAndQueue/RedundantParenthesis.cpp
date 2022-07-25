#include<iostream>
#include <string>
#include<stack>

using namespace std;

bool isOperator(char s){
    switch (s)
    {
    case '+':
    case '-':
    case '*':
    case '^':
    return true;
        break;
    
    default:
    return false;
        break;
    }
}

/** Pop anc check operator*/
bool popAndCheckOperator(stack<char> &bracketStack, char closeBracket){
            bool op=false;
            while(!bracketStack.empty() &&  bracketStack.top()!=closeBracket){  
             if(isOperator(bracketStack.top())){
             op= true;
             }
            bracketStack.pop(); 
            }

            if(bracketStack.top()== closeBracket)
            {
                bracketStack.pop();
            }
    return op;        
        
}



bool isRedundantParenthesis(string exp){
    stack<char> bracketStack;
    for(auto s : exp){
       switch (s)
       {
       case ')':
            if(!popAndCheckOperator(bracketStack,'(')){
                return false;
            }

            break;
       case '}':
       if(!popAndCheckOperator(bracketStack,'{')){
                return false;
            }
            break;
       case ']':
       if(!popAndCheckOperator(bracketStack,'[')){
                return false;
            }
         break;   

       default:
           bracketStack.push(s);
           break;
       } 
    }

 return true;  
}

int main(){
    string exp = "(a+b+c)+(d)";
    if(isRedundantParenthesis(exp)){
        cout<<"Not Redundant";
    }else{
        cout<<"Redundant";
    }
   //cout<<isBalanced(exp);

}

