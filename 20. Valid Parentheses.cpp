#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
      if (c == '{' || c == '[' || c == '(')
        st.push(c);
      if (st.empty())
        return false;
      if (c == '}' || c == ']' || c == ')') {
        char current = st.top();
        st.pop();
        if (current == '{' && c != '}' || current == '(' && c != ')' ||
            current == '[' && c != ']')
          return false;
      }
    }
    return st.empty();
  }
};