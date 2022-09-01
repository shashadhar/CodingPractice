#include<iostream>
#include<vector>

using namespace std;

/**
 * Initialize the 3 pointers such that low and mid will point to 0th index and high pointer will point to last index
int low = arr[0]

int mid = arr[0]

int high = arr[n – 1]

Now there will 3 different operations / steps based on the value of arr[mid] and will be repeated until mid <= high.

arr[mid] == 0:
swap(arr[low], arr[mid])
low++, mid++

arr[mid] == 1:
mid++

arr[mid] == 2:
swap(arr[mid], arr[high])
high–-;
 */

void sortColors(vector<int>& nums) {
        int lo = 0; 
        int hi = nums.size() - 1; 
        int mid = 0; 

        while (mid <= hi) { 
            switch (nums[mid]) { 

            // If the element is 0 
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
         
    }

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
