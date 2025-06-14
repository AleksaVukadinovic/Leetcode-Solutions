#include <cstdint>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<bool>> visited;
  const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int16_t m, n;
  const vector<vector<char>> *gridPtr;

  void markIslandAsVisited(const int i, const int j) {
    visited[i][j] = true;
    for (const auto &[dx, dy] : directions) {
      int ni = i + dx, nj = j + dy;
      if (ni >= 0 && ni < m && nj >= 0 && nj < n && (*gridPtr)[ni][nj] == '1' &&
          !visited[ni][nj]) {
        markIslandAsVisited(ni, nj);
      }
    }
  }

public:
  int numIslands(const vector<vector<char>> &grid) {
    m = grid.size();
    n = grid[0].size();
    gridPtr = &grid;
    visited.assign(m, vector<bool>(n, false));

    int islands = 0;
    for (int16_t i = 0; i < m; i++) {
      for (int16_t j = 0; j < n; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          islands++;
          markIslandAsVisited(i, j);
        }
      }
    }
    return islands;
  }
};

// Optimized by ChatGPT
class Solution2 {
public:
  int numIslands(vector<vector<char>> &grid) {
    int16_t m = grid.size(), n = grid[0].size(), islands = 0;

    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    auto dfs = [&](int i, int j, auto &&dfs_ref) -> void {
      grid[i][j] = '0';
      for (int d = 0; d < 4; ++d) {
        int ni = i + dx[d], nj = j + dy[d];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
          dfs_ref(ni, nj, dfs_ref);
        }
      }
    };

    for (int16_t i = 0; i < m; ++i) {
      for (int16_t j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          islands++;
          dfs(i, j, dfs);
        }
      }
    }

    return islands;
  }
};
