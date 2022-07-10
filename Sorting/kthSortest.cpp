#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// not working
int partition(vector<int> &a1, int begin, int end)
{
    int pivot = a1[begin];
    int i = begin;
    int j = end;

    while (i < j)
    {
        do
        {
            i++;
        } while (a1[i] <= pivot);

        do
        {
            j--;
        } while (a1[j] > pivot);

        if (i < j)
        {
            swap(a1[i], a1[j]);
        }
    }

    swap(a1[begin], a1[j]);

    return j;
}

int partition2(vector<int> &A, int start, int end)
{
    int i = start + 1;
    int piv = A[start]; // make the first element as pivot element.
    for (int j = start + 1; j <= end; j++)
    {
        /*rearrange the array by putting elements which are less than pivot
           on one side and which are greater that on other. */

        if (A[j] < piv)
        {
            swap(A[i], A[j]);
            i += 1;
        }
    }
    swap(A[start], A[i - 1]); // put the pivot element in its proper place.
    return i - 1;             // return the position of the pivot
}

int k_sortest(vector<int> &A, int start, int end,int k)
{
// assuming k inside the array

    // stores the position of pivot element
    int piv_pos = partition2(A, start, end);
    
    if(piv_pos > k){
     return k_sortest(A, start, piv_pos - 1,k);
    }else if (piv_pos < k){
     return k_sortest(A, piv_pos + 1, end,k);
    } else{
        return A[k];
    }
        
}

// replace space with %20
int main()
{
    vector<int> arr{10,5,2,0,7,6,4};

    cout<<k_sortest(arr, 0, arr.size() - 1,2);
    
}
