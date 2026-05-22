class Solution
{
public:
  bool validate_numbers(vector<int>& nums)
  {
    if (nums.size() < 2) return true;
    array<int, 9> c;
    for (int n : nums) {
      int i = n - 1;
      if (c[i]) return false;
      c[i]++;
    }
    return true;
  }

  bool check_row(vector<vector<char>>& board, int r)
  {
    vector<int> nums;
    nums.reserve(9);
    for (char ch : board[r]) {
      if (ch == '.') continue;
      nums.push_back(ch - '0');
    }
    return validate_numbers(nums);
  }

  bool check_column(vector<vector<char>>& board, int c)
  {
    vector<int> nums;
    nums.reserve(9);
    for (int r = 0; r < 9; r++) {
      char ch = board[r][c];
      if (ch == '.') continue;
      nums.push_back(ch - '0');
    }
    return validate_numbers(nums);
  }

  bool check_sub_box(vector<vector<char>>& board, int r, int c)
  {
    vector<int> nums;
    nums.reserve(9);
    for (int i = r; i < r + 3; i++) {
      for (int j = c; j < c + 3; j++) {
        char ch = board[i][j];
        if (ch == '.') continue;
        nums.push_back(ch - '0');
      }
    }
    return validate_numbers(nums);
  }

  bool isValidSudoku(vector<vector<char>>& board)
  {
    for (int r = 0; r < 9; r++) {
      if (!check_row(board, r)) return false;
    }
    for (int c = 0; c < 9; c++) {
      if (!check_column(board, c)) return false;
    }
    for (int r = 0; r < 9; r += 3) {
      for (int c = 0; c < 9; c += 3) {
        if (!check_sub_box(board, r, c)) return false;
      }
    }
    return true;
  }
};
