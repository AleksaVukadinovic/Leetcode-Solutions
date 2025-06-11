#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    char n = matrix.size(), m = matrix[0].size(), i = 0, j = m - 1;

    while (i < n && j > -1) {
      int cur = matrix[i][j];
      if (cur == target)
        return true;
      if (target > cur)
        i++;
      else
        j--;
    }

    return false;
  }
};