class Solution
{
public:
  int diagonalSum(vector<vector<int>>& mat)
  {
    auto n = mat.size();
    size_t j = n - 1;
    int s = 0;
    for (size_t i = 0; i < n; i++) {
      s += mat[i][i] + mat[i][j--];
    }
    if (n & 1) s -= mat[n / 2][n / 2];
    return s;
  }
};
