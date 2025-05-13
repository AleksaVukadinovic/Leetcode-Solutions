#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int16_t l = 0, r = nums.size() - 1, m;
    while (l <= r) {
      m = (l + r) >> 1;
      if (nums[m] < target)
        l++;
      else
        r--;
    }
    return l;
  }
};