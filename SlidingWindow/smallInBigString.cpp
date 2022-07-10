#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void  subarraySum(int * a , int n, int k){
    
}

string find_smallest_window(string big, string small){
    int fp[256]={0},fs[256]={0};
    int small_len= small.length();
    for(int i=0;i<small.length();i++){
        fp[small[i]]++;
    }


    int start =0;int cnt=0;
    int min_win_size = INT32_MAX;
    int win_start =0;
    int win_size;
    for(int i=0;i<big.length();i++){
           char ch = big[i];
           fs[ch]++;

           if(fp[ch]!=0 && fs[ch]<= fp[ch]){
             cnt = cnt+1;
           }
           
           // contract the window
           if(cnt == small_len ){
              while(fp[big[start]] == 0 || fs[big[start]] > fp[big[start]]){
                start++;
              }

             win_size = i-start+1;
             if(win_size < min_win_size){
                min_win_size = win_size;
                win_start = start;
             }

           }
    }
  if(win_start == -1){
    return "";
  }else{
   return  big.substr(win_start,min_win_size);
  }
}


// one small string and big string, find smallest window in big string which has all the charaters of
// small string
int main(){
    string big = "fizzbuzz";
    string small = "fuzz";

    cout<<find_smallest_window(big , small);

}
