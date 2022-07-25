#include<iostream>
#include <string>
#include<stack>
#include<vector>
#include <queue>
#include<deque>
#include<unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> stockSpan(vector<int> v){
    vector <int> result;
    stack<pair<int,int>> stk;

    for(int i =0;i<v.size();i++){
        if(stk.empty()){
            stk.push(make_pair(i,v[i]));
            result.push_back(1);
        }else{
           while(!stk.empty() && stk.top().second <= v[i]){
           stk.pop();
           }
          if(!stk.empty()){
          result.push_back(i-stk.top().first);
          }else{
              result.push_back(i+1);
          }
          stk.push(pair{i,v[i]});

        }
       
    }
 return result;   

}

// find the no of days, a stock is greater than the previous days including the current day
// stock span
int main(){
    vector<int> stock={100,80,60,70,60,75,85};
    vector<int> res = stockSpan(stock);
    for(auto s : stock){
        cout<<s<<" ";
    }
    cout<<endl;
    for(auto s : res){
        cout<<s<<" ";
    }

}

