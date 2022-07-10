#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;

int findSmallestDifference(int A[], int B[],
                           int m, int n)
{
    // Sort both arrays using
    // sort function
    sort(A, A + m);
    sort(B, B + n);
 
    int a = 0, b = 0;
 
    // Initialize result as max value
    int result = INT_MAX;
 
    // Scan Both Arrays upto
    // sizeof of the Arrays
    while (a < m && b < n)
    {
        if (abs(A[a] - B[b]) < result)
            result = abs(A[a] - B[b]);
 
        // Move Smaller Value
        if (A[a] < B[b])
            a++;
 
        else
            b++;
    }
 
    // return final sma result
    return result;
}
 
int main()
{
    vector<int> a = {23,5,10,17,30};
    vector<int> b = {26,134,135,14,19};
    int minDiff=INT_MAX;
    pair<int,int> p;
    for(auto a1 : a)
        for(auto b1 : b){
            int diff = abs(a1-b1);
              if( diff< minDiff){
                  minDiff = diff;
                  p ={a1,b1};
              }
        }

 cout<<"Pair:"<<p.first<<p.second;

    

    
}