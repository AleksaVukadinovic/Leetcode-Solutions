#include <algorithm>
#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int8_t n = nums.size(), i = n - 1, j;
    if (n <= 1)
      return;
    for (j = n - 2; j >= 0; j--)
      if (nums[j] < nums[j + 1])
        break;
    if (j >= 0) {
      while (nums[i] <= nums[j])
        i--;
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + j + 1, nums.end());
  }
};