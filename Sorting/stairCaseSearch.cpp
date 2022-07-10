#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2)
{
   return s1 + s2 < s2 + s1;

}

pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    // max row ie last row
    int i = m-1;    
    // 1st column element 
    int j=0;
    pair<int,int> result = {-1,-1};
    while(i>=0 && j<=n-1){

        if(v[i][j]==k){
            return result = {i,j};
        }else if(v[i][j]<k){
          j++;
        }else{
            i--;
        }
    
    }
return result;
}



// Staircase search
// Given m*n matrix ,where elements are sorted row and column wise.
// we have to search a int K on linear time
int main()
{
    
    // we will start from last row, max element
    //if last row 1st element is smaller then the element in the same row 
    // if last row 1st element is bigger decrease the row
    vector <vector<int>>v {{1,4,9},{2,5,10},{6,7,11}};
    cout << search(3,3,v,7).first;

}