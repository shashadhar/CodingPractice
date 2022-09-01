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

bool binarySearch(vector<int> ar, int k){
    int start=0,end = ar.size() -1;
    int mid = (start + end)/2;
    while(start <= end ){
        if(ar[mid] == k){
            return true;
        }else if(ar[mid] > k){
            end = mid -1;
        }else {
            start = mid +1;
        }
        mid = (start + end)/2;
    }
   return false; 
}

bool searchInMatrix(vector<vector<int>> mat, int k){

    // We can directly use binary search as follows
    //row = index/column.size()
    // col = index/column.size()
         int lo = 0;
        if(!mat.size()) return false;
        int hi = (mat.size() * mat[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(mat[mid/mat[0].size()][mid % mat[0].size()] == k) {
                return true;
            }
            if(mat[mid/mat[0].size()][mid % mat[0].size()] < k) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false; 

}

/** 
 * Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

Given matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row
Input: matrix = 
[[1,3,5,7],
[10,11,16,20],
[23,30,34,60]], 

target = 3

Output: true
**/

int main(){

vector<vector<int>> mat ={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
cout<<searchInMatrix(mat,3);
}
