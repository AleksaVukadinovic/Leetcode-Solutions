class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    int i = 1, j = 2, res = 0;
    for (char k = 3; k <= n; k++) {
      res = i + j;
      i = j;
      j = res;
    }
    return res;
  }
};