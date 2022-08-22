#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include<unordered_map>

using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){
       vector<int> common;
       unordered_map<int,bool> map;
       for(auto s : v1){
           map[s] = true;
       }

       for(auto s : v2){
           if(map[s]==true){
               common.push_back(s);
           }
       }
       sort(common.begin(),common.end());
       return common;

}

// Given two vectors , task to find common elements
int main()
{
  vector<int> a = {1,45,54,71,76,12};
  vector<int> b = {1,7,5,4,6,12};
  vector<int> resut = commonElements(a,b);
  for(auto s: resut){
      cout<< s;
  }

}