#include <bits/stdc++.h>


using namespace std;


int kthElement(vector<int> ar1 , vector<int> ar2, int k){
    int m = ar1.size();
    int n = ar2.size();

    if(m>n)
        return kthElement(ar2,ar1,k);//ensuring that binary search happens on minimum size array
        
    
    // create the cut
    // Ex m = 4 and n = 5. For k = 3 , we can not take max 4 element from ar1 so high = min(k,m)
    // k = 8, then from ar1 we have to take min  k-n elements this low = max(0, k-n)
   int low = max(0,k-n), high = min(k,m);
        
    while(low <= high) {
        int mid = (low + high) >> 1; 
        int cut1 = mid;
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : ar1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : ar2[cut2 - 1];
        int r1 = cut1 == m ? INT_MAX : ar1[cut1]; 
        int r2 = cut2 == n ? INT_MAX : ar2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 0;
}


/*
Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays.

Example 1:

Input format: arr1 = [1,4,7,10,12], arr2 = [2,3,6,15]

Output format : 6.00000

Explanation:
Merge both arrays. Final sorted array is [1,2,3,4,6,7,10,12,15]. We know that to find the median we find the mid element. Since, the size of the element is odd. By formula, the median will be at [(n+1)/2]th position of the final sorted array. Thus, for this example, the median is at [(9+1)/2]th position which is [5]th = 6.
Example 2:

Input: arr1 = [1], arr2 = [2]

Output format:
 1.50000

Explanation:
 
Merge both arrays. Final sorted array is [1,2]. We know that to find the median we find the mid element. Since, the size of the element is even. By formula, the median will be the mean of elements at [n/2]th and  [(n/2)+1]th position of the final sorted array. Thus, for this example, the median is (1+2)/2 = 3/2 = 1.50000.
*/
int main()
{

    vector<int> arr1 ={1,4,7,10,12};
    vector<int> arr2 ={2,3,6,15};
   cout<< kthElement(arr1,arr2, 1);
   cout<< kthElement(arr1,arr2, 2);
   cout<< kthElement(arr1,arr2, 3);
   cout<< kthElement(arr1,arr2, 4);
   cout<< kthElement(arr1,arr2, 5);
   cout<< kthElement(arr1,arr2, 6);
   cout<< kthElement(arr1,arr2, 7);
   cout<< kthElement(arr1,arr2, 8);
   cout<< kthElement(arr1,arr2, 9);
 

}