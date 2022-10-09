#include<bits/stdc++.h>
using namespace std;
stack<int> st;

void clearstack(){
    while(!st.empty()){
        st.pop();
    }
}

vector<int> leftsmaller(vector<int> &arr, int n){
    vector<int> res(n);
    for(int i = 0; i<n; i++){
        while (!st.empty() and arr[st.top()] >= arr[i]){
            st.pop();
        }
        res[i] = (st.empty()) ? -1 : st.top(); 
        st.push(i);
    }
    return res;
}

vector<int> rightsmaller(vector<int> &arr, int n){
    vector<int> res(n);
    for(int i = n-1; i>=0; i--){
        while (!st.empty() and arr[st.top()] >= arr[i]){
            st.pop();
        }
        res[i] = (st.empty()) ? n : st.top(); 
        st.push(i);
    }
    return res;
}

vector<int> maxMinWindow(vector<int> arr, int n) {
    vector<int> right, left;
    
    left = leftsmaller(arr, n);
    clearstack();
    right = rightsmaller(arr, n);

    vector<int> ans(n, 0);

    for(int i = 0; i<n; i++){
        int pos = right[i] - left[i] - 1;
        ans[pos - 1] = max(ans[pos - 1] , arr[i]);
    }

    for(int i = n-2; i>=0; i--){
        ans[i] = max(ans[i], ans[i+1]);
    }

    return ans;
}


int main(){
    vector<int> ele = {4,0,-1,3,5,3,6,8};
    maxMinWindow(ele,8);
}