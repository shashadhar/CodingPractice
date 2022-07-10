#include <iostream>
#include "string.h"
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string movie = "I liked the movie, acting in the movie was great!";
    string search = "movie";
    vector<int> result = {};
    int beginPos = 0;
    int index = movie.find(search, beginPos);
    int occurence = 0;
    while (index != -1)
    {
        result.push_back(++occurence);
        //cout << ++occurence << " occurence found."<<endl;
        beginPos = index + search.length();
        index = movie.find(search, beginPos);
    }
}
