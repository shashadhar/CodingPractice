#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void generateBrackets(int n,string out,int open,int close ,int i){
    if(i==2*n){
        cout<<out<<endl;
        return;
    }
    
    if(n>open){
        generateBrackets(n,out+'(',open+1,close,i+1);
    }
    if(open>close){
        generateBrackets(n,out+')',open,close+1,i+1);
    }



}


// Generate brackets so that we have balanced parenthesis always, n is the no of close or open bracket
int main()
{
int N = 4;
string out;
generateBrackets(3,out,0,0,0);    
}
