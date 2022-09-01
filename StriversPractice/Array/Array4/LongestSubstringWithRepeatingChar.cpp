#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <map>

using namespace std;

int longestSubstringWithoutRepeating(string s){
    unordered_map<char, int> occurence;
    int n = s.length();
    int currentStart=0,currentEnd=0;
    int maxlength=0, currentLen =0;
    int maxStart, maxEnd;
    for (int i = 0; i < n; i++)
    {
        // check if it is repeating 
        if(occurence.find(s[i])!= occurence.end()){
            // check the boundary
            int index = occurence[i];
            if(index >=currentStart){
                // repeat case
                if(currentLen > maxlength){
                    maxlength = currentLen;
                    maxStart = currentStart;
                    maxEnd = currentEnd;
                }
                currentStart = i;
                currentLen =1;
                currentEnd = i;
            }else{
               currentLen = currentLen + 1; 
               currentEnd = i;
            }
        }else{
            currentLen = currentLen + 1;
            currentEnd = i;
        }
        occurence[s[i]] = i;
    }
    return maxlength;
}

/**
 Length of Longest Substring without any Repeating Character
Problem Statement: Given a String, find the length of longest substring without any repeating character.

Examples:

Example 1:

Input: s = ”abcabcbb”

Output: 3

Explanation: The answer is abc with length of 3.

Example 2:

Input: s = ”bbbbb”

Output: 1

Explanation: The answer is b with length of 1 units.
 */

int main(){
string s = "takeUforward";
cout<< longestSubstringWithoutRepeating(s);

    
}
