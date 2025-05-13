#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    vector<int> res = {-1, -1};
    if (r == -1)
      return res;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    if (l >= nums.size() || nums[l] != target)
      return res;
    res[0] = l;
    l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] > target)
        r = m - 1;
      else
        l = m + 1;
    }
    if (r < 0 || nums[r] != target)
      return res;
    res[1] = r;

    return res;
  }
};
