#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void test (int a[]){
    int i=2;
    a[i]=9;
}

vector<int> sortBalls_DNF(vector<int> a){
    //sort the balls in place
    int n = a.size();
    
    int s = 0;
    int e = n-1;
    int mid = 0;
    
    while(mid<=e){
        if(a[mid] == 0){
            swap(a[s++],a[mid++]);
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{
            swap(a[mid],a[e--]);
        }
    }
    return a;
}

vector<int> sortBalls(vector<int> &balls){
    vector<int> cnt(3,0);
    int n = balls.size();
    for(int i =0;i<n;i++){
      cnt[balls[i]]++;
    }
    int j=0;
   for(int i =0;i<3;i++){
       while (cnt[i]--)
       {
           balls[j++]=i;
       }
       
   }
return balls;

}



// Array containg Red =0, blue = 1, gree = 2 in random order
// need to sort the array in one scan without using extra space
// 

int main()
{
    vector<int> balls {
    0,0,1,2,0,1,2,0
    };

      sortBalls(balls);
   for(auto s: balls){
       cout<<s<<" ";
   }

   int* b = new int(3);
   *(b+0) = 1;
   *(b+1) = 4;
   *(b+2) = 5;
   test(b);
   cout<<b[2];
    
}
