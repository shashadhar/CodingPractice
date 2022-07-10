#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


/* Iterative Function to calculate (x^y) in O(log y) */
int power_iterative(int x, int y)
{
     
    // Initialize answer
    int res = 1;
     
    // Check till the number becomes zero
    while (y)
    {
         
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x);
             
        // y = y/2
        y = y >> 1;
         
        // Change x to x^2
        x = (x * x);
    }
    return res;
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power_modulo(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


double power(int a, int b)
{

    if (b == 0)
    {
        return 1;
    }

    if (b < 0)
    {
        return 1 / power(a, -b);
    }

    if (b % 2 == 0)
    {
        return power(a, b / 2) * power(a, b / 2);
    }
    else
    {
        return a * power(a, (b - 1) / 2) * power(a, (b - 1) / 2);
    }
}

long long int power_rec(int a, int b)
{
    long long int y;
    if (b == 0)
    {
        return 1;
    }

    if (b < 0)
    {
        return 1 / power_rec(a, -b);
    }

    if (b % 2 == 0)
    {
        y = power_rec(a, b / 2);
        y = y*y;
    }
    else
    {
        y= a * power_rec(a, (b - 1));
    }
    return y;
}


int main(){
    cout << power(2,5)<<endl;
    cout<< power_rec(2,5)<<endl;

}
