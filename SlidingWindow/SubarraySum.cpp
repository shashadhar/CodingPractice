#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void  subarraySum(int * a , int n, int k){
    int i =0,j=0;
    int cs=0;
    while(j<n){
        cs = cs+a[j];
        j++;

        // remove elements from left till cs > sum and i < f
        while (i<j && cs>k){
            cs = cs - a[i];
            i++;
        }

      if(cs == k){
          cout<< i <<"-"<<j-1<<endl;
      }  
    }
      
 return;
}


// max sub array sum 
int main(){
    int a[]={1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(a)/sizeof(int);
    int k =8;
    subarraySum(a,n,k);



}
