#include<bits/stdc++.h>
using namespace std;

void subString(char str[], int n)
{
    // Pick starting point
    for (int i = 0; i <n; i++)
    {   
        // Pick length
        for (int len = 1; len <= n - i; len++)
        {
            //  Print characters from current
            // starting point to current ending
            // point. 
            int j = i + len - 1;           
            for (int k = i; k <= j; k++)
                cout << str[k];
             
            cout << endl;
        }
    }
}
 
// Driver program to test above function
int main()
{
    char str[] = "abc";
    subString(str, strlen(str));
    return 0;
}