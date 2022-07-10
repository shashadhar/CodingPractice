#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// expected complexity o(n)
// Each element in the array is the product of all other element except the element itself
int main()
{
    vector<int> arr={1,2,3,4};
    int n = arr.size();
    vector<int> leftProd(n,1);
    vector<int> rightProd(n,1);
    vector <int> totalProd(n,1);
    for(int i=1;i<n;i++){
        leftProd[i]=leftProd[i-1]*arr[i-1];
    }
    
     for(int i=n-2;i>=0;i--){
        rightProd[i]=rightProd[i+1]*arr[i+1];
        totalProd[i]=leftProd[i]*rightProd[i];

        
    }
    totalProd[n-1]=leftProd[n-1]*rightProd[n-1];
    for(auto t : totalProd){
        cout << t<<" ";
    }
    
}