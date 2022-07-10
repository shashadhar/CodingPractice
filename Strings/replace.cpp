#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// replace space with %20
int main()
{
    char input[1000] = "Hello world,  how are you?";
    int noOfSpace=0;
    char*arr = input;
    string s = arr;
    for(int i=0;arr[i]!='\0';i++){
      if(arr[i] == ' '){
          noOfSpace++;
      }
    }
    cout<<"No of space"<<noOfSpace;
    int originalLen = strlen(arr);
    int id = originalLen + 2 * noOfSpace;

   for(int i=originalLen-1;i>=0;i--){
      if(arr[i] == ' '){
          arr[id-1]='0';
          arr[id-2]='2';
          arr[id-3]='%';
          id=id-3;
      }else{
          arr[id-1]=arr[i];
          id--;
      }
    }

   cout<<input<<endl;
   cout<<arr<<endl; 
     
    
}
