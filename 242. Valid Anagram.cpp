#include <string>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    int n = s.size();
    int set1[26], set2[26];
    for (int i = 0; i < n; i++) {
      set1[s[i] - 'a']++;
      set2[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
      if (set1[i] != set2[i])
        return false;
    return true;
  }
};