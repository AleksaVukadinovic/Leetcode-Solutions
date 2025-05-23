#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int n = height.size();
    int area = 0, l = 0, r = n - 1;

    while (l < r) {
      area = max(area, (r - l) * min(height[l], height[r]));
      if (height[l] < height[r])
        l++;
      else
        r--;
    }

    return area;
  }
};