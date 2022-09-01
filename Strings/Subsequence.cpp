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
  for (int i = 1; i < pow(2,len); i++)
  {
    cout<< subSeqBinary(ss, i, len) << " ";
  }
}


bool compare(int n1, int n2)
{
  string s1 = to_string(n1);
  string s2 = to_string(n2);
  return s1 + s2 > s2 + s1;
}

int main()
{
  string input = "abc";
  vector<string> list;
  //subsequence("abc", "", list);
  getSubsequence("abc",3);
}
