#include <cstdint>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string &s) {
    int16_t longest = 0, n = s.size();
    stack<int16_t> st;
    st.push(-1);
    for (int16_t i = 0; i < n; i++) {
      if (s[i] == '(')
        st.push(i);
      else {
        st.pop();
        if (st.empty())
          st.push(i);
        else if (i - st.top() > longest)
          longest = i - st.top();
      }
    }
    return longest;
  }
};