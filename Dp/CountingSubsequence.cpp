#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


int countSubSequence(string s1, string s2,int i,int j){
   if((i==-1 && j==-1) || j==-1){
       return 1;
   }
   if(i==-1){
       return 0;
   }

    if(s1[i] == s2[j]){
        // macth from both the string
        int op1 = countSubSequence(s1,s2,i-1,j-1);

        // dont want to match the current but want to match with other
        int op2 = countSubSequence(s1,s2,i-1,j);
        return op1+op2;
    }

    return countSubSequence(s1,s2,i-1,j);

}



int main(){
    string a = "ABCECDG";
    string b ="ABC";
    cout<<"Count sub sequence"<<countSubSequence(a,b,a.length()-1,b.length()-1);

}