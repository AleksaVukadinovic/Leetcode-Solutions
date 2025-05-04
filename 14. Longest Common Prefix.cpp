#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string pref = "";
    sort(strs.begin(), strs.end());
    for (int i = 0; i < min(strs[0].length(), strs[strs.size() - 1].length());
         i++) {
      if (strs[0][i] != strs[strs.size() - 1][i])
        return pref;
      pref += strs[0][i];
    }
    return pref;
  }
};