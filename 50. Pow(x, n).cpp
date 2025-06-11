#include <cmath>
using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    if (!x)
      return 0;
    if (x == 1 || !n)
      return 1;

    long long absN = abs((long long)n);
    double res = 1;

    while (absN) {
      if (absN & 1)
        res *= x;
      x *= x;
      absN = absN >> 1;
    }

    return n < 0 ? 1 / res : res;
  }
};