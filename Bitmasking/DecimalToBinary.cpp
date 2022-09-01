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



void binaryToDecimal(int num){
    vector<int> bin;
    while (num > 0)
    {      
    if(num & 1){
        bin.push_back(1);
    }else{
        bin.push_back(0);
    }
    num = num >> 1;
    }

    for(int i = bin.size();i>=0;i--){
        cout<< bin[i];
    }

}

int main(){
    binaryToDecimal(10);

}
