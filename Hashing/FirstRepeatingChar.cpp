#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include<unordered_map>
#include <string>

using namespace std;


char firstRepeatingChar(string input){
    char s ='\0';
    unordered_map<int, bool> repeat;
    for(auto s : input){
        if(repeat.count(s)!=0){
         return s;
        }else{
            repeat[s]=true;
        }
    }
    return s;
}

// Given two vectors , task to find common elements
int main()
{
  string s = "dhard";
  cout<< firstRepeatingChar(s);

}