#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include<unordered_map>
#include <string>
#include<set>
#include <map>
#include<climits>

using namespace std;
string s = "thequickbrownfox";
string words[] ={"the", "quickbrown","brown","fox","quick"};

int minHelper(string s ,set<string> &wordSet,int idx){
    // base case 
    if(s[idx] =='\0'){
      return 0;
    }

    int ans = INT_MAX;
    string currentString = "";

    for(int j = idx;s[j]!='\0';j++){
       currentString = currentString + s[j];
       if(wordSet.find(currentString)!= wordSet.end()){
           int remaining = minHelper(s,wordSet,j+1);
           if(remaining!=-1){
               ans = min(ans,1+remaining);
           }
       }
    }
 if(ans == INT_MAX){
     return -1;
 }
return ans;
}


int minBars(){
    set<string> wordsSet;
    for(auto s :words ){
        wordsSet.insert(s);
    }

    int out = minHelper(s,wordsSet,0);
    return out -1;
}



int main(){

    cout<< minBars();

}