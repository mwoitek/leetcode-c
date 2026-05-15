class Solution
{
public:
  int pivotIndex(vector<int>& nums)
  {
    auto n = nums.size();
    auto prefix = vector<int>(n + 1);
    partial_sum(begin(nums), end(nums), next(begin(prefix)));
    for (int i = 0; i < n; i++) {
      auto sum_left = prefix[i] - prefix[0];
      auto sum_right = prefix[n] - prefix[i + 1];
      if (sum_left == sum_right) return i;
    }
    return -1;
  }
};
