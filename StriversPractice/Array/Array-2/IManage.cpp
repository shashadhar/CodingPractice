
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <map>


using namespace std;

bool solution(vector<int> &a, int k){
int n = a.size();
for(int i =0; i<n-1;i++){
    if(a[i]+1 < a[i+1]){
        return false;
    }
}

if(a[0]!=1 || a[n-1] !=k){
    return false;
}else{
    return true;
}
}

int main(){

    vector<int> a ={1,1,2,2,3,3};
    cout<< solution(a,3);

}