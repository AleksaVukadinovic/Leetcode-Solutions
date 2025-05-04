#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    vector<string> rows(numRows, "");
    int currentRow = 0;
    bool isFirstOrLast = true;

    for (int i = 0; i < s.length(); i++) {
      if (currentRow == 0 || currentRow == numRows - 1)
        isFirstOrLast = !isFirstOrLast;

      rows[currentRow] += s[i];
      currentRow = isFirstOrLast ? currentRow - 1 : currentRow + 1;
    }

    string ret;
    for (int i = 0; i < numRows; ++i)
      ret += rows[i];

    return ret;
  }
};