#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generateStrings(string input,string output,int i=0){

    if(input[i] == '\0'){
     cout<<output<<endl;
     return;
    }

    int digit = input[i]-'0'; 
    if(digit == 0 || digit==1){
        generateStrings(input,output,i+1);
    }

    for(int k=0;k<keypad[digit].size();k++){
        generateStrings(input,output+keypad[digit][k],i+1);
    }
    return;
}





// Generate brackets so that we have balanced parenthesis always, n is the no of close or open bracket
int main()
{
   string input="34";
   //cin>>input;
   string output;
   generateStrings(input,output);
}
