#include <vector>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int i = 0, maxReach = 0, n = nums.size();
    while (i < n && i <= maxReach) {
      maxReach = max(maxReach, i + nums[i]);
      i++;
    }
    return maxReach >= n - 1;
  }
};