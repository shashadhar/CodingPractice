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

// x to the power of y
int power(int x, int y){
    int res =1;
    while(y>0){
     if(y & 1){
         res = res * x;
     }
     x = x*x;
     y = y >>1;
    }
    return res;
}

int powerRec(int x, int y){
    if (y ==0){
        return 1;
    }
    if(y%2 == 1){
     return x * powerRec(x, y-1);
    }else{
        int t = powerRec(x, y/2);
        return  t * t;
    }
}

/*Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).
* Log n time */
int main(){
 cout<< powerRec(2,10);

}
