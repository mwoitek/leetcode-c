class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    auto r = matrix.size();
    auto c = matrix.back().size();
    auto n = r * c;
    vector<int> nums;
    nums.reserve(n);
    int l = 0;
    while (true) {
      for (int j = l; j < c - l; j++) {
        nums.push_back(matrix[l][j]);
      }
      if (nums.size() == n) break;
      for (int i = l + 1; i < r - l - 1; i++) {
        nums.push_back(matrix[i][c - l - 1]);
      }
      if (nums.size() == n) break;
      for (int j = c - l - 1; j >= l; j--) {
        nums.push_back(matrix[r - l - 1][j]);
      }
      if (nums.size() == n) break;
      for (int i = r - l - 2; i >= l + 1; i--) {
        nums.push_back(matrix[i][l]);
      }
      if (nums.size() == n) break;
      l++;
    }
    return nums;
  }
};
