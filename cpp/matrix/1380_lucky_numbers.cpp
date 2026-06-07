class Solution
{
public:
  int row_min(vector<vector<int>>& matrix, size_t i)
  {
    auto row = matrix[i];
    auto it = min_element(row.begin(), row.end());
    return *it;
  }

  int col_max(vector<vector<int>>& matrix, size_t j, size_t m)
  {
    int cm = 0;
    for (size_t i = 0; i < m; i++) {
      cm = max(cm, matrix[i][j]);
    }
    return cm;
  }

  vector<int> luckyNumbers(vector<vector<int>>& matrix)
  {
    auto m = matrix.size();
    auto n = matrix.front().size();

    auto r = vector<int>(m);
    for (size_t i = 0; i < m; i++) {
      r[i] = row_min(matrix, i);
    }

    auto c = vector<int>(n);
    for (size_t j = 0; j < n; j++) {
      c[j] = col_max(matrix, j, m);
    }

    vector<int> ans;
    for (size_t i = 0; i < m; i++) {
      auto rm = r[i];
      for (size_t j = 0; j < n; j++) {
        auto v = matrix[i][j];
        if (v == rm && v == c[j]) ans.push_back(v);
      }
    }
    return ans;
  }
};
