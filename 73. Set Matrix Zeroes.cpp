#include <cstdint>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    uint8_t n = matrix.size(), m = matrix[0].size();
    unordered_set<uint8_t> rows, cols;
    for (uint8_t i = 0; i < n; i++)
      for (uint8_t j = 0; j < m; j++)
        if (!matrix[i][j]) {
          rows.insert(i);
          cols.insert(j);
        }

    for (uint8_t i = 0; i < matrix.size(); i++) {
      bool shouldReplace = rows.find(i) == rows.end() ? false : true;
      if (shouldReplace) {
        for (int j = 0; j < matrix[0].size(); j++)
          matrix[i][j] = 0;
      } else {
        for (int j = 0; j < matrix[0].size(); j++)
          if (cols.find(j) != cols.end())
            matrix[i][j] = 0;
      }
    }
  }
};