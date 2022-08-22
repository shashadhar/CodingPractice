#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include<unordered_map>
#include <string>
#include<set>
#include <map>

using namespace std;

vector<int> generateHash(string s , int i, int j){
    vector<int> hass(26,0);
    for(int k=i;k<=j;k++){
        char c = s[k];
        hass[c-'a']++;
    }
 return hass;
}


int anagrams(string s){
   
   // complex obect as a key , can not be set as key in unordered set
   map<vector<int>,int> hashFr;
    
   // create the all sub string
   for(int i =0;i<s.length(); i++){
       for (int  j = i; j <s.length(); j++){

           vector<int> hass =   generateHash(s,i,j);
           hashFr[hass]++;
       }         
   }

   // calculate the pairs
   int ans = 0;
   for(auto s: hashFr){
       int fr = s.second;
       if(fr >= 2){
         ans = ans + fr *(fr-1)/2;
       }
   }

   return ans;
}



int main(){

    cout<< anagrams("abba");

}