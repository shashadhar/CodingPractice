#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// gets the unique substring
string uniqueSubstring(string input, int n)
{
    unordered_map<char, int> lastOccurence;
    int i = 0, j = 0;
    int maxWindowSize = 0;
    int maxwindowStart = -1;
    int curWindowSize = 0;
    while (j < n)
    {
        int present = lastOccurence.count(input[j]);
        if (present)
        {
            int lastPos = lastOccurence[input[j]];
            // we got already same char present
            if (lastPos >= i)
            {
                i = lastPos + 1;
            }
        }

        curWindowSize = (j - i) + 1;
        if(curWindowSize>maxWindowSize){
            maxwindowStart = i;
            maxWindowSize = curWindowSize;
        }
        lastOccurence[input[j]] = j;
        j++;
    }
    return input.substr(maxwindowStart, maxWindowSize);
}

// unique substring
// Ex: PrateekBhaiya
// ekBhaiya

int main()
{
    string input = "prateekbhaiya";
    // cout<<"Enter input";
    // cin>>input;
    int n = input.length();
    cout << uniqueSubstring(input, n);
}
