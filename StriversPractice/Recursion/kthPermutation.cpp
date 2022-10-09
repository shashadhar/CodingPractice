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

string getPermutation(int n, int k) {
      int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
    }

/*
Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) find the Kth permutation sequence.

For N = 3  the 3!  Permutation sequences in order would look like this:-



Note: 1<=K<=N! Hence for a given input its Kth permutation always exists

Examples:

Example 1:

Input: N = 3, K = 3
 
Output: “213”

Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 3 corresponds to the third sequence.

Example 2:

Input: N = 3, K = 5 

Result: “312”

Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 5 corresponds to the fifth sequence.
*/



int main() {
  int n = 3, k = 3;
  string ans = getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}