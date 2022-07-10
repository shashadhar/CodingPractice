#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include<set>

using namespace std;
vector<string> v;


void findPermutations(char* inp,int i){
     if(inp[i]=='\0'){
         cout<<inp<<endl;
         v.push_back(inp);
         return;
     }

     for(int j =i; inp[j]!='\0';j++){
         swap(inp[i],inp[j]);
         findPermutations(inp,i+1);
         swap(inp[i],inp[j]);
     }


}


// Generate all permutations of strings
// Ex: abc, acb,bac,bca,cab,cba
int main()
{
 string s = "PQR";
 int n = s.length();
 char *ss  = new char(n+1);
 for(int i =0;i<n;i++){
    ss[i]=s[i];
 }

 ss[n]='\0';

 findPermutations(ss,0);

 set<string> st;
    for(int i=0; i<v.size(); i++){
        st.insert(v[i]);
    }
    v.clear();
    for(auto x:st){
        v.push_back(x);
    }

    cout<<"Sorted permutations"<<endl;
     for(auto x:st){
        cout<<x<<endl;
    }
 
}
