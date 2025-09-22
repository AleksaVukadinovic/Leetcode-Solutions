// Da li su reci anagrami, dve reci kao string, true/false da li su anagrami
// teacher cheater
// ['t' -'a'] ++
// [1. 0, 0,0, 2...]
// ['c' - 'a'] --
// [0,0,0, ...]
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  string s1 = "teacher";
  string s2 = "cheater";
  bool is_anagram = true;
  unordered_map<char, int> counts;
  for (char c : s1)
    counts[c]++;
  for (char c : s2)
    counts[c]--;
  for (auto x : counts)
    if (x.second != 0) {
      is_anagram = false;
      break;
    }
  cout << is_anagram << endl;
  return 0;
}