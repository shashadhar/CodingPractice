#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


void removeDupWord(string str)
{
    // Used to split string around spaces.
    istringstream ss(str);
 
    string word; // for storing each word
 
    // Traverse through all words
    // while loop till we get
    // strings to store in string word
    while (ss >> word)
    {
        // print the read word
        cout << word << "\n";
    }
}

//using strtok
void tokenize(string s){
    char * temp = const_cast<char*>(s.c_str());
    char* token =  strtok(temp, " ");
    while(token != NULL){
        cout<< token <<endl;
        token = strtok(NULL," ");

    } 
}

// tokenize the string
int main()
{
    string s = "Hello world,  how are you?";
    stringstream ss (s);
    string word;
    int count=0;
    while(getline(ss,word,' ')){
        cout<<word<<endl;
        count++;
    }

    cout<<"Count:"<<count;

    cout<<"again" <<endl;
    tokenize(s);

    cout<< "using isstringstream"<<endl;
    removeDupWord(s);
}
