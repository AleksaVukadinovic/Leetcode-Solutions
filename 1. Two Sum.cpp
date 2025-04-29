#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> seen;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (seen.find(target - nums[i]) != seen.end())
        return {i, seen[target - nums[i]]};
      seen[nums[i]] = i;
    }
    return {0, 0};
  }
};
