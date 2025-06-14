#include <unordered_map>
#include <vector>
using namespace std;

// Should be done using Boyer-Moore but I cba
class Solution {
public:
  vector<int> majorityElement(const vector<int> &nums) {
    int n = nums.size(), threshold = n / 3;
    vector<int> res;
    unordered_map<int, int> occurences;
    for (int i = 0; i < n; i++)
      occurences[nums[i]]++;
    for (const pair<int, int> p : occurences)
      if (p.second > threshold)
        res.push_back(p.first);
    return res;
  }
};