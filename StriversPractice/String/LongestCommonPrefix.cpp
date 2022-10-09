#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> words){
  string res = words[0];
  int len = res.length();
  for(int i = 1; i< words.size();i++){
     string currentWord = words[i];
     int currentWordLen = currentWord.length();
     len = min(len,currentWordLen);
     for(int j =0; j< len;j++){
          if(currentWord[j]== res[j]){
            continue;
          }else{
            len= j;
            break;
          }
     }
  }

res = res.substr(0,len);
return res;
}


/**
Longest Common Prefix
Easy

10465

3400

Add to List

Share
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 */
int main(){
    vector<string> list = {"aa","aa","aaaa"};
    cout<< longestCommonPrefix(list)<<endl;

}