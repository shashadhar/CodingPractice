#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;



bool compare(int n1, int n2)
{
  string s1 = to_string(n1);
  string s2 = to_string(n2);
  return s1 + s2 > s2 + s1;
}

// lexio graphically largest number
string lexicographicallyLargerNo(vector<int> numbers)
{
  // complete this method and return the largest number you can form as a string

  sort(numbers.begin(), numbers.end(), compare);
  string result;
  for (auto s : numbers)
  {
    result = result + to_string(s);
  }
  return result;
}

/**
 * Return larger no lexicographically
 * by joining all the strings ex 3, 30 it should be 330
 * 
 */
int main()
{
  cout<<lexicographicallyLargerNo({10, 11, 20, 3, 30});

}
