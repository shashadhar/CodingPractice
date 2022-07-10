#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int n1, int n2)
{
   string s1= to_string(n1);
   string s2 = to_string(n2);

   return s1 + s2 > s2 + s1;

}

// replace space with %20
int main()
{
    vector<int>  arr{10,11,20,3,30};
    sort(arr.begin(),arr.end(),compare);
    for(auto a: arr){
        cout<<a;
    } 
    
}
