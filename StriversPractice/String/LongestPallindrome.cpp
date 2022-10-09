#include<bits/stdc++.h>

using namespace std;

int checkPallindrome(string ss){
  int n = ss.length();
  int i =0,j = n-1;
  while(i< n){
    if(ss[i] != ss[j]){
      return false;
    }
    i++, j--;
  }
return true;  
}


// Approach take each element as midddle and check its left and right 
// if left and right are same continue to count pallindrom length 
string longestPallindrome(string ss){
  int n = ss.length();
  string res ="";
  int resLen =0;
  for(int i =0;i< ss.length();i++){
    int l=i, r =i;
    while(l>=0 && r <n && ss[l] == ss[r]) {
        if(r-l+1 > resLen){
            resLen = r-l+1;
            res = ss.substr(l,resLen);
        }
        l--;
        r++;

    }
    l = i, r= i+1;
    while(l>=0 && r <n && ss[l] == ss[r]) {
        if(r-l+1 > resLen){
            resLen = r-l+1;
            res = ss.substr(l,resLen);
        }
        r++;

    }

  }
  
return res;

}



/*
Longest Palindromic Substring
Medium

21696

1245

Add to List

Share
Given a string s, return the longest palindromic substring in s.

A string is called a palindrome string if the reverse of that string is the same as the original string.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/
int main(){
 cout<< longestPallindrome("abccbc")<<endl;
}