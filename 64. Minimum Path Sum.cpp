#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int16_t m = grid.size(), n = grid[0].size();
    for (int16_t i = 1; i < m; i++)
      grid[i][0] += grid[i - 1][0];
    for (int16_t i = 1; i < n; i++)
      grid[0][i] += grid[0][i - 1];
    for (int16_t i = 1; i < m; i++)
      for (int16_t j = 1; j < n; j++)
        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

    return grid[m - 1][n - 1];
  }
};