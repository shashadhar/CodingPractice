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

// Smallest string lexiographically
int main()
{
    vector<string>  arr{"a","ab","aba"};
    sort(arr.begin(),arr.end(),compare);
    for(auto a: arr){
        cout<<a;
    } 
    
}
