#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/*
Sample input:
---------------
3 
92 022
82 12
77 13
2 false numeric

Result
--------
82 12
77 13
92 022
*/

int convertToInt(string s){
    int value = 0;
    int multiples = 1;
    for(int i = s.length()-1; i>=0; i--){
      value = s[i]-'0' * multiples + value;
      multiples = multiples * 10;
    }
  return value;  
}

// Extract key at position
string extractKeyAtPos(string s, int keyPos){
  string result =  strtok((char*)s.c_str()," ");
  while (keyPos>1){

    result = strtok(NULL," ");
    keyPos--;
  }
  return result;
}

bool lexicompare(pair<string,string> s1, pair<string,string> s2){
    return s1.second < s2.second;
}

bool numericCompare(pair<string,string> s1, pair<string,string> s2){
   return convertToInt(s1.second)<convertToInt(s2.second);
}

int main()
{
  int n;
  cin>>n;
  cin.get(); // extra spaces after the 3 
 
  string temp;
  vector<string> input;
  vector<pair<string,string>> allvaues;
  for(int i=0;i<n;i++){
      getline(cin,temp);
      input.push_back(temp);
  }  

  int key;
  string reversal,ordering;
  cin>>key>>reversal>>ordering;

  for(int i =0;i<n;i++){
      allvaues.push_back({input[i],extractKeyAtPos(input[i],key)});
  }

  if(ordering == "numeric"){
      sort(allvaues.begin(),allvaues.end(),numericCompare);

  }else{
      sort(allvaues.begin(),allvaues.end(),lexicompare);
  }

  if(reversal=="true"){
      reverse(allvaues.begin(),allvaues.end());
  }

  for(auto s : allvaues){
      cout<<s.first<<endl;

  }



  
  

  

}
