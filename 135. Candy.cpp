#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int16_t n = ratings.size();
    vector<int16_t> candies(n, 1);
    for (int16_t i = 1; i < n; i++)
      if (ratings[i] > ratings[i - 1])
        candies[i] = candies[i - 1] + 1;
    for (int16_t i = n - 2; i >= 0; i--)
      if (ratings[i] > ratings[i + 1])
        candies[i] = max(candies[i], static_cast<int16_t>(candies[i + 1] + 1));

    int32_t sum = 0;
    for (int16_t c : candies)
      sum += c;
    return sum;
  }
};