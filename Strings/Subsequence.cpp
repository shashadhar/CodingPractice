#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/*
Subsequence of a string
abc
a
c
ab
bc
abc
*/

void subsequence(string s, string out, vector<string> &allSubs)
{
  if (s.empty())
  {
    cout << out << endl;
    allSubs.push_back(out);
    return;
  }

  // taking first char
  subsequence(s.substr(1), out + s[0], allSubs);

  // without taking
  subsequence(s.substr(1), out, allSubs);
}

string subSeqBinary(string ss, int binary, int len)
{
  string sub = "";
  for (int i = 0; i < len; i++)
  {
    if (binary & (1 << i))
    {
      sub = sub + ss[i];
    }
  }
  return sub;
}

void getSubsequence(string ss, int len)
{
  // get the binary nos
  for (int i = 1; i < len; i++)
  {
    subSeqBinary(ss, i, len);
  }
}

string convert_to_digital_time(int minutes)
{
  // complete this function

  string result = "";
  int hour = minutes / 60;
  int minutesLeft = minutes - (hour * 60);
  if (minutesLeft < 10)
  {
    result = to_string(hour) + ":" + "0" + to_string(minutesLeft);
  }
  else
  {
    result = to_string(hour) + ":" + to_string(minutesLeft);
  }
  return result;
}

bool compare(int n1, int n2)
{
  string s1 = to_string(n1);
  string s2 = to_string(n2);
  return s1 + s2 > s2 + s1;
}

// lexio graphically largest number
string concatenate(vector<int> numbers)
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

int main()
{
  string input = "abc";
  vector<string> list;
  subsequence("abc", "", list);
  cout << convert_to_digital_time(125);

  concatenate({10, 11, 20, 3, 30});
  cout << endl
       << compressString("aaaabbbxxxxxx");
}
