#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


// str is the input the string
string compressString(const string &str)
{
  // complete the function to return output string
  int n = str.length();
  string result;
  for (int i = 0; i < n; i++)
  {

    int count = 1;
    while (i < n - 1 && str[i] == str[i + 1])
    {
      count++;
      i++;
    }
    result = result + str[i];
    result = result + to_string(count);
  }
  if (result.length() < n)
  {
    return result;
  }
  else
  {
    return str;
  }
}


// str is the input the string
string compressString2(const string &str)
{

  vector<int > count(26);
  // complete the function to return output string
  int n = str.length();
  string result;
  for (int i = 0; i < n; i++)
  {

    int count = 1;
    while (i < n - 1 && str[i] == str[i + 1])
    {
      count++;
      i++;
    }
    result = result + str[i];
    result = result + to_string(count);
  }
  if (result.length() < n)
  {
    return result;
  }
  else
  {
    return str;
  }
}
/**
Write a function to perform basic string compression using the counts of repeated characters, 
also known as Run Length Encoding. Let see one example, the input string "aaaabcccccaaa" would 
become "a4b1c5a3". If the "compressed" string would not become smaller than the original string,
your function should return the input string. You can assume the string has only uppercase and lowercase letters. 
You may use the to_string(int) method to convert an integer into string.
 */
int main()
{
  cout << endl
       << compressString("aaaabbbxxxxxx");
}
