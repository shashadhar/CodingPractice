#include<bits/stdc++.h>

using namespace std;

void occurence(string ss, string pat, int index, vector<int> &result){
   int foundIndex = ss.find(pat,index);          
   if(foundIndex!= -1){
    cout<< foundIndex << endl;
    result.push_back(foundIndex);
    occurence(ss,pat,foundIndex+1,result);
   }else{
    return;
   }
}

int main(){
string ss = "AABAACAADAABAABA";
string pat = "AABA";
vector<int> res;
occurence(ss,pat,0,res);

}