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

vector<int> generateHash(string str)
{
    vector<int> hass(26, 0);
    for (auto s : str)
    {
        char c = s;
        hass[c - 'a']++;
    }
    return hass;
}

vector<vector<string>> groupAnagrams(vector<string> strs)
{
    //Write your code here. Do not modify the function or the parameters.
    map<vector<int>, vector<string>> groupedAnagrams;

    for (auto s : strs)
    {
        vector<int> hashz = generateHash(s);
        if (groupedAnagrams.count(hashz) != 0)
        {
            groupedAnagrams[hashz].push_back(s);
        }
        else
        {
            groupedAnagrams[hashz] = {s};
        }
    }

    vector<vector<string>> result;
    for (auto s : groupedAnagrams)
    {
        result.push_back(s.second);
    }

    return result;
}

int main()
{
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(words);
    for (auto s : result)
    {
        for (auto s1 : s)
        {
            cout << s1;
        }
        cout << endl;
    }
}