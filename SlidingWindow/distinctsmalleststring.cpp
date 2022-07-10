#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


string find_distinct_smallest_window(string ss){
    int fp[256]={0};
    int total_distinct=0;
    for(int i =0;i<ss.length();i++){
       fp[ss[i]]=1;
       if(fp[ss[i]==0]){
        total_distinct= total_distinct +1;
       }
    }
    
    int start =0;
    int cnt=0;
    for(int i=0;i<ss.length();i++){
       if(fp[ss[i]]==1){
        cnt = cnt+1;
       }

      if(cnt = total_distinct){
        
      }

    }
}


// find smallest window which contains all distict characters of the string
int main(){
    string big = "fizzbuzz";
    string small = "fuzz";

    cout<<find_distinct_smallest_window(big);

}
