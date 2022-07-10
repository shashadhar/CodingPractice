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




// Sorted array with empty string added in between, we have to search a string
// since we have empty string in between

// brute force , search linearly o(n), need to improve using modified binary search

int main()
{
    vector<string>  arr {"ai","","","bat","","","car","cat","","","dog","e"};
    int start =0,index=-1;
    string search = "eee";
    int end = arr.size() -1;
    int mid = (start + end)/2;
    while(mid>=start && mid<=end){

        if(arr[mid] == ""){
            // get the first nearest non empty position
            int left = mid-1,right =mid+1;
            while ((left>=0 && arr[left]=="") && (right >= end && arr[right]=="")){
                left--;
                right++;
            }
         if(left>0 && right>end){
             index = -1;
             break;
         } 
         mid = arr[left]!=""?left:right;
        }

        if(arr[mid] == search){
            index =  mid;
            break;
        }else if(arr[mid] > search){
            end = mid -1;
        }else{
            start = mid + 1;
        }

        mid = (start+end)/2;

    }
cout << "Strinf found at:"<<index;
}