#include <vector>
using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector<vector<int>> matrix(n, vector<int>(m));
    if (obstacleGrid[0][0])
      return 0;
    matrix[0][0] = 1;

    for (int i = 1; i < n; i++) {
      if (obstacleGrid[i][0]) {
        matrix[i][0] = 0;
        for (int k = i + 1; k < n; k++)
          matrix[k][0] = 0;
        break;
      }
      matrix[i][0] = 1;
    }

    for (int i = 1; i < m; i++) {
      if (obstacleGrid[0][i]) {
        matrix[0][i] = 0;
        for (int k = i + 1; k < m; k++)
          matrix[0][k] = 0;
        break;
      }
      matrix[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
      for (int j = 1; j < m; j++)
        matrix[i][j] =
            obstacleGrid[i][j] ? 0 : matrix[i - 1][j] + matrix[i][j - 1];

    return matrix[n - 1][m - 1];
  }
};