#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> v1, pair<int,int> v2){
    return v1.second < v2.second;
}


int countActivites(vector<pair<int,int> > v){
    //Complete this method
    
    sort(v.begin(),v.end(),compare);
    int count = 1;
    int finish = v[0].second;
    
    for(int i=1;i<v.size();i++){
        if(v[i].first>=finish){
            count++;
            finish = v[i].second;
        }
    }
    return count;
}

// expected complexity o(n)
// Each element in the array is the product of all other element except the element itself
int main()
{
   vector<pair<int,int>> v = {{7,9},{0,10},{4,5},{8,9},{4,10}};
   cout<<countActivites(v);
float a = 3.14;
double b = 3.14;
if(a==b){
      cout<<"Coding";
}
else{
     cout<<"Minutes";
}


}