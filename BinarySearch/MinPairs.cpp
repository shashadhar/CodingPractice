#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> minAbsInArray(vector<int> ar1, vector<int> ar2){
  pair<int,int> result;
  sort(ar1.begin(), ar1.end());
  int diff = INT_MAX;
  for(auto x : ar2){
     int lb = lower_bound(ar1.begin(),ar1.end(),x)- ar1.begin();

     // get the smaller element than x
     if(lb>=1 && x - ar1[lb-1] < diff){
       diff = x - ar1[lb-1];
       result = {x, ar1[lb-1]};
     }

     if(lb!= ar1.size() && ar1[lb] - x < diff){
       diff = ar1[lb] - x;
       result = {x, ar1[lb]};
     }

  }

  return result;

}


// we need to find min absolute difference pair
// will sort the first array and loop through the other array
// the lower bound should return first greater or equal element
// lb -1 is smaller element than the value
// lb is greater or equal element
int main(){

vector<int> a1 = {-1,5,10,20,3};
vector<int> a2 = {26,134,135,15,17};
pair p = minAbsInArray(a1, a2);
cout<<endl;
cout<< p.first;
cout<< p.second;
}