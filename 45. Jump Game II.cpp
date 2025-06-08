#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int16_t n = nums.size(), res = 0, furthest = 0, last = 0;
    for (int16_t i = 0; i < n - 1; i++) {
      int16_t jmp = i + nums[i];
      furthest = furthest > jmp ? furthest : jmp;
      if (i == last) {
        last = furthest;
        res++;
      }
    }
    return res;
  }
};