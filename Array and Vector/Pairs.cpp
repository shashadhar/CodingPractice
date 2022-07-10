#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr={10,5,2,3,-6,9,11};
    unordered_set<int> table;
    int s = 4;
   
    for(auto ele: arr){
        
        int p = s - ele;
        if(table.find(p)!= table.end()){
           cout<<"Pair found:"<<ele<<","<<p<<endl; 
        }else{
            table.insert(ele);
        }


    }



    
}