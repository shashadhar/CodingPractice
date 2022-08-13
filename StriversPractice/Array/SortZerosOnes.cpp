#include<iostream>
#include<vector>

using namespace std;

void sortArray(int arr[], int n){

     int countOne=0, countTwo=0, countZero=0;
    for(int i =0;i<n;i++){
        if(arr[i]==0){
            countZero = countZero +1;

        }else if(arr[i]==1){
            countOne = countOne + 1;

        }else{
            countTwo = countTwo + 1;
        }
    }
    
    for(int i=0;i<n;i++){
        if(i<countZero){
            arr[i]=0;
        }else if(i< countZero + countOne){
            arr[i]=1;
        }else{
            arr[i]=2;
        }
    }
    
  
}


/**
 * Sort an array of 0's, 1's and 2's
 */
int main(){

    int arr[] = {2,0,2,1,1,0};
    sortArray(arr,6);

    for(int i=0;i<6;i++){
        cout<< arr[i]<<",";
    }
}
