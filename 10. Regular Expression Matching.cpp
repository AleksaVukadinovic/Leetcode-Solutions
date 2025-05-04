#include <string>
using namespace std;
class Solution {
public:
  bool isMatch(const string &s, const string &p) {
    return matchHelper(s, p, 0, 0);
  }

private:
  bool matchHelper(const string &s, const string &p, size_t i, size_t j) {
    if (j == p.size())
      return i == s.size();

    bool curMatch = (i < s.size()) && (p[j] == s[i] || p[j] == '.');

    if (j + 1 < p.size() && p[j + 1] == '*')
      return matchHelper(s, p, i, j + 2) ||
             (curMatch && matchHelper(s, p, i + 1, j));

    return curMatch && matchHelper(s, p, i + 1, j + 1);
  }
};