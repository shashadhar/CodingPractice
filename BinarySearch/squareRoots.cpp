#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


float squareRoot(int n, int p){
  int s=0,e = n;
  int square =0;
  int mid = (s+e)/2;
  float result = 0;
  while (s <= e){
    int ss = mid*mid;
      if(ss==n){
        return mid;
      }else if(ss < n){
       result = mid;
       s = mid+1;
      }else{
        e = mid -1;
      }
      mid = (s+e)/2;
  }


  // get the precision values , we will increase the value by .1 then .01 and then .001
  float inc = 0.1;

  for(int place=1; place<=p;place++){
        while (result * result <=n)
        {
          result = result + inc;
        }
        result = result - inc;
       inc = inc/10;
  }

   return result;
   
}




 int main() {
     cout<<squareRoot(10,3);
 }