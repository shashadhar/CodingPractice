#include <bits/stdc++.h>

using namespace std;



class ST {

    private:
    int t=-1;
    vector<int> contents;


    public:
    int size;

    ST(int s){
        size = s;
        contents = vector<int>(size,-1);
    }

    int top(){
       int result = -1; 
        if(t==-1){
            cout<< "Stack is empty";
        }else{
         result = contents[t]; 
        } 
     cout<< "Stack top:"<< result<<endl;   
     return result;   
    }

    void pop(){
        int result = -1; 
        if(t==-1){
            cout<< "Stack is empty";
        }else{
         cout<< "Poped element:" << contents[t-1]<<endl;   
         contents.erase(contents.begin()+t-1);  
         t = t -1; 
        }
    }
        

    void push(int el){
             
       // check stack full
       if(t == size -1){
        cout<< "Stack is full";
       }else{
        t= t +1;
        contents[t] = el;
       }
    }
};


int main(){

ST s (3);
s.push(3);
s.push(6);
s.push(7);

s.top();
s.pop();
s.top();

}