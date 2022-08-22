#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <map>

using namespace std;

/* 
* Merge sorted array with extra space
*/
vector<int> mergeSortedArray(vector<int> ar1, vector<int> ar2)
{
    vector<int> merged;
    int i = 0, j = 0, m = 0, n1 = ar1.size(), n2 = ar2.size();
    int totalElements = ar1.size() + ar2.size();
    while (i < n1 && j < n2)
    {

        if (ar1[i] < ar2[j])
        {
            merged.push_back(ar1[i++]);
        }
        else
        {
            merged.push_back(ar2[j++]);
        }
    }

    while (i < n1)
    {
        merged.push_back(ar1[i++]);
    }
    while (j < n2)
    {
        merged.push_back(ar2[j++]);
    }
    return merged;
}

void sortWithoutExtraSpace(vector<int> a1, vector<int> a2)
{
    int n1 = a1.size();
    int n2 = a2.size();

    for (int i = 0; i < n1; i++)
    {
        if (a1[i] > a2[0])
        {
            swap(a1[i], a2[0]);

            // we need to sort the array 2 after swap as it may not be in sorted
            // order, we can use insertion sort for this purpose
            int first = a2[0];
            int k = 1;
            for (; k < n2 && a2[k] < first; k++)
            {
                a2[k - 1] = a2[k];
            }
            a2[k - 1] = first;
        }

        //
    }

    // print element
    for (auto s : a1)
    {
        cout << s << " ";
    }
    cout << endl;
    for (auto s : a2)
    {
        cout << s << " ";
    }
}

void sortWithoutExtraSpaceUsingGapMethod(vector<int> a1, vector<int> a2)
{
    int n1 = a1.size();
    int n2 = a2.size();
    int gap = ceil((float)(n1 + n2) / 2);

    while (gap > 0)
    {
        int i = 0;
        int j = gap;
        while (j < n1 + n2)
        {
            if (j < n1 && i < n1 && a1[i] > a1[i])
            {
                swap(a1[i], a1[j]);
            }
            else if (j >= n1 && i < n1 && a1[i] > a2[j - n1])
            {
                swap(a1[i], a2[j - n1]);
            }
            else if (j >= n1 && i >= n1 && a2[i - n2] > a2[j - n1])
            {
                swap(a2[i - n1], a2[j - n1]);
            }
            i++;
            j++;
        }

        if (gap == 1)
        {
            gap = 0;
        }
        else
        {
            gap = ceil(gap / 2);
        }
    }

    // print element
    for (auto s : a1)
    {
        cout << s << " ";
    }
    cout << endl;
    for (auto s : a2)
    {
        cout << s << " ";
    }
}

/*Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
 Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that 
 it contains the last M elements. */
int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    vector<int> res = mergeSortedArray(arr1, arr2);
    for (auto s : res)
    {
        cout << s;
    }

    sortWithoutExtraSpace(arr1, arr2);
    
    cout<<endl;
    sortWithoutExtraSpaceUsingGapMethod(arr1, arr2);
}

