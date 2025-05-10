#include <cstdint>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int16_t j = 1, n = nums.size();
    for (int16_t i = 1; i < n; i++)
      if (nums[i] != nums[i - 1]) {
        nums[j] = nums[i];
        j++;
      }
    return j;
  }
};