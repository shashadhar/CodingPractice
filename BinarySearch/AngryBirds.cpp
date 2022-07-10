#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


float squareRoot(int n, int p){
  int s=0,e = n;
  int square =0;
  int mid = (s+e)/2;
  float result = 0;
  while (s <= e){
    int ss = mid*mid;
      if(ss==n){
        return mid;
      }else if(ss < n){
       result = mid;
       s = mid+1;
      }else{
        e = mid -1;
      }
      mid = (s+e)/2;
  }


  // get the precision values , we will increase the value by .1 then .01 and then .001
  float inc = 0.1;

  for(int place=1; place<=p;place++){
        while (result * result <=n)
        {
          result = result + inc;
        }
        result = result - inc;
       inc = inc/10;
  }

   return result;
   
}

bool canPlaceBirds(vector<int> nests , int distance, int noOfBirdsToPlace){
 bool result = false;
 int n = nests.size() -1;
 int currentBirdPlaced = nests[0];
 int birdPlaced = 1;
 for(int i=1; i<=n;i++){
   int nextBirdPlaced = nests[i];
   if(nextBirdPlaced - currentBirdPlaced >= distance){
     birdPlaced ++;
     currentBirdPlaced = nextBirdPlaced;
   }
   if(birdPlaced == noOfBirdsToPlace){
     result = true; 
     break;
   }
  
 } 


  return result;
}


// we have to place birds such that we can have max distance in between
// We will search the distances based on bs and chekc if possible to place the birds
 int main() {
   vector<int> nests {1,2,4,8,9};
   int noOfBirdsToPlace = 3;
   sort(nests.begin(),nests.end());
   int n = nests.size()-1;
   int s =0, e = nests[n] - nests[0];
   int mid= (s + e)/2;
   int result = -1;
   while (s<=e){
     if(canPlaceBirds(nests,mid,noOfBirdsToPlace)){
       result = mid;
       s = mid+1;
     }else {
       e = mid -1;
     }

     mid = (s + e)/2;
   }

cout<<result;
    
 }