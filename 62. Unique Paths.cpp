#include <vector>
using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> matrix(n, vector<int>(m));
    matrix[0][0] = 1;
    for (char i = 1; i < n; i++)
      matrix[i][0] = 1;
    for (char i = 1; i < m; i++)
      matrix[0][i] = 1;
    for (char i = 1; i < n; i++)
      for (char j = 1; j < m; j++)
        matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
    return matrix[n - 1][m - 1];
  }
};