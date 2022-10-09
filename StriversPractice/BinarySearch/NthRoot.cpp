#include <bits/stdc++.h>


using namespace std;

double getNTimes(double n, double no)
{
    double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * no;
    }
    return result;
}

double findNthRoot(int n, int no, int noOfPrecision)
{

    // get the middle point
    int s = 0, e = no;
    int mid = (s + e) / 2;
    int result;
    while (e >= s)
    {
        int nTimesMid = getNTimes(n, mid);
        if (nTimesMid == no)
        {
            result = mid;
            break;
        }
        if (nTimesMid > no)
        {
            // reduce the end
            e = mid - 1;
        }
        else
        {
            result = mid;
            // increase the start
            s = mid + 1;

        }
        mid = (s + e) / 2;
    }

    // done with int part . calculate the precision part
    double inc = 0.1;
    int precisionLimit = 0;
    double FinalResult = result;
    double resultInc;
    while (precisionLimit < noOfPrecision)
    {
        FinalResult = FinalResult + inc;
        resultInc = getNTimes(n, FinalResult);
        if(resultInc == no){
            break;
        }
        if (resultInc > no)
        {
            FinalResult = FinalResult - inc;
            inc = inc / 10;
            precisionLimit = precisionLimit + 1;
        }
    }

    return FinalResult;
}

/*
Given two numbers N and M, find the Nth root of M.

The nth root of a number M is defined as a number X when raised to the power N equals M.

Example 1:

Input: N=3 M=27

Output: 3

Explanation: The cube root of 27 is 3.
Example 2:

Input: N=2 M=16

Output: 4

Explanation: The square root of 16 is 4

*/
int main()
{
    cout << findNthRoot(2,10,3);
}