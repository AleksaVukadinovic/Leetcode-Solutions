#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  int len;
  vector<string> res;

public:
  void allParentheses(string s, int l, int r) {
    if (r == len && l == len) {
      res.push_back(s);
      return;
    }
    if (l < len)
      allParentheses(s + '(', l + 1, r);
    if (r < l)
      allParentheses(s + ')', l, r + 1);
  }

  vector<string> generateParenthesis(int n) {
    len = n;
    allParentheses("", 0, 0);
    return res;
  }
};