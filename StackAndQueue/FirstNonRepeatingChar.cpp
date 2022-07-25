#include<iostream>
#include <string>
#include<stack>
#include<vector>
#include <queue>
#include<unordered_map>

using namespace std;

vector<char> firstNonRepeatingChar(string ss){
    vector<char> result;
    int fr[256]={0};
    queue<char> uniqueChar;
    for(auto s: ss){  
         fr[s]++;
        if(fr[s]==1){
            uniqueChar.push(s);              
            result.push_back(uniqueChar.front());
            
        }else{           
         while(!uniqueChar.empty() && fr[uniqueChar.front()]>=2){   
         uniqueChar.pop();
         }
         if(!uniqueChar.empty()){
         result.push_back(uniqueChar.front());
         }else{
             result.push_back('0');
         }
        }
       
    }
    return result;

}

int main(){
    string exp = "aabccbcd";
    vector<char>result = firstNonRepeatingChar(exp);
   for(auto s : exp){
       cout<<s<<" ";
   }
   cout<<endl;

    for(auto s : result){
        cout<<s<<" ";
    }
    

}

