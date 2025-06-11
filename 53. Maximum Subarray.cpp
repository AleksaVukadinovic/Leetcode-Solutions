#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxSum = INT_MIN, currentSum = 0, l = 0, d = 0, n = nums.size();
    while (d < n) {
      currentSum += nums[d];
      maxSum = maxSum > currentSum ? maxSum : currentSum;
      if (currentSum < 0) {
        l = ++d;
        currentSum = 0;
      } else
        d++;
    }
    return maxSum;
  }
};