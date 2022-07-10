#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int ladderClimb(int n){
    
    if(n<0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    int a = ladderClimb(n-1);
    int b = ladderClimb(n-2);
    int c = ladderClimb(n-3);
    return a + b +c;
}


// Given a ladder containing N steps , you can jump of 1 ,2 or 3 at each step
// find no of ways to climp the ladder
int main()
{
    int N = 4;
     cout<<ladderClimb(N);
    
}
