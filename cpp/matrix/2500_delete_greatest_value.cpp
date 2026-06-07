class Solution
{
public:
  int row_max(vector<vector<int>>& grid, size_t i, vector<vector<bool>>& skip)
  {
    int rm = -1;
    size_t j = 0;
    auto n = grid.front().size();
    for (size_t k = 0; k < n; k++) {
      if (skip[i][k]) continue;
      auto v = grid[i][k];
      if (v > rm) {
        rm = v;
        j = k;
      }
    }
    skip[i][j] = true;
    return rm;
  }

  int deleteGreatestValue(vector<vector<int>>& grid)
  {
    auto m = grid.size();
    auto n = grid.front().size();
    auto skip = vector<vector<bool>>(m, vector<bool>(n));
    int ans = 0;
    while (n > 0) {
      int dm = -1;
      for (size_t i = 0; i < m; i++) {
        dm = max(dm, row_max(grid, i, skip));
      }
      ans += dm;
      n--;
    }
    return ans;
  }
};
