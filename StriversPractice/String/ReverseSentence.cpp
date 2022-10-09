#include<bits/stdc++.h>

using namespace std;

// solution 2

// traverse from end order

void reverse(string st){

    string temp="";
    string ans =" ";
    for(int i = 0;i<st.length(); i++){
       
       // word break;
       if(st[i] == ' '){
        ans = temp + " " + ans;
        temp ="";
       }else{
        temp = temp + st[i];
       }
    }

    ans = temp +" " +  ans;
    cout<<ans;
}



void reverseString(string st){

     auto pos = st.find(" ");   
     if(pos == string::npos){
        cout<< st << endl;
        return;
     }
     string word = st.substr(0,pos);
     string s = st.substr(pos+1);
     reverseString(s);
     cout<< word <<endl;
}

int main(){
    string s = "geeksforgeeks a computer science";
    reverseString(s);

    cout<< endl;
    reverse(s);
}