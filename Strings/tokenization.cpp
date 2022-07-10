#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

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
}
