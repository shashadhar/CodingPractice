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

int countPathGrid(int i , int j,int m , int n){
    // we have reached last cell
    if(i == m-1 && j == n-1){
     return 1;
    }
    int x =0,y=0;
    if(i< m-1 && j <= n-1 ){
    x = countPathGrid(i+1,j,m,n);
    }
    
    if( i <= n-1 && j< n-1){
    y = countPathGrid(i, j+1,m,n);
    }
    return x +y;

}


/* Given a matrix m X n, count paths from left-top to the right bottom of a matrix 
* with the constraints that from each cell you can either only move to the rightward direction 
or the downward direction. */

int main(){
 cout<< countPathGrid(0,0,2,2);
}
