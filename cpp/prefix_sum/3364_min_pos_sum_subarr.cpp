const int BIG_INT = numeric_limits<int>::max();

class Solution
{
public:
  int minimumSumSubarray(vector<int>& nums, int l, int r)
  {
    auto n = nums.size();
    auto pre = vector<int>(n + 1);
    partial_sum(nums.begin(), nums.end(), next(pre.begin()));
    auto m = BIG_INT;
    for (size_t i = 0; i < n; i++) {
      for (size_t j = i + l - 1; j < min(i + r, n); j++) {
        int s = pre[j + 1] - pre[i];
        if (s > 0) m = min(m, s);
      }
    }
    return m < BIG_INT ? m : -1;
  }
};
