#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void removeFirst(string &s){
    unordered_map <string,int> counts;
     for(int i=0;i<s.length();i++){
        // counts[s.at(i)]= i;
     }

    for(int i=0;i<s.length();i++){
        int index;
        index = s.find(s[i],i+1);
        if(index !=-1){
          //remove and reverse 
           s.erase(i,1);
           reverse(s.begin(),s.end());
           i=-1;
        } 

    }
    
}

int main()
{
    string t = "dddd";
    removeFirst(t);
    cout<<t;
    
}
