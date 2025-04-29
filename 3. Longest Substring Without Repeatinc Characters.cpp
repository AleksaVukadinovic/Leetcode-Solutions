#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    unordered_map<char, int> lastSeen;
    int longest = 0, i = 0;
    for (int j = 0; j < n; j++) {
      if (lastSeen.find(s[j]) != lastSeen.end() && lastSeen[s[j]] >= i)
        i = lastSeen[s[j]] + 1;
      lastSeen[s[j]] = j;
      longest = max(longest, j - i + 1);
    }
    return longest;
  }
};