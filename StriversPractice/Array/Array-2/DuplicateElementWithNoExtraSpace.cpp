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

int duplicatte(vector<int> arr){
    int res = -1;
    int n = arr.size();
    for(int i= 0; i < arr.size() ; i++){
       int index =  arr[i]% n ;
        arr[index] = arr[index] + n;
    }

    for(int i = 0; i < arr.size() ; i++){
       if(arr[i] >= 2 * n){
        return i;
       }
    }
    return res;
}


int main(){
    vector<int> ar = {1,3,4,2,2};
    cout << duplicatte(ar);

}