#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;

void solve(string &s,set<string>&st,int idx,vector<string>&res,string curr){
   if(idx==s.length()){
       curr.pop_back();
       res.push_back(curr);
       return;
   }
   string temp="";
   for(int i=idx;i<s.length();i++){
       temp.push_back(s[i]);
       if(st.count(temp)){
           solve(s,st,i+1,res,curr+temp+" ");
       }
   }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
   vector<string> res;
   set<string> st(dictionary.begin(),dictionary.end());
   solve(s,st,0,res,"");
   return res;
}


/**
 Word breark and get the possible no of sentences
 Same as minbar problem
 */

int main()
{
 vector<string> dict = {"god", "is", "now", "no", "where", "here"};
 string input = "godisnowherenowhere";
 vector<string> result = wordBreak(input,dict);
 for(auto s : result){
  cout<< s <<endl;
 }   
}
