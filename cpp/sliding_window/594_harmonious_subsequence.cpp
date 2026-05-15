class Solution
{
public:
  int findLHS(vector<int>& nums)
  {
    sort(begin(nums), end(nums));
    auto n = nums.size();
    int i = 0;
    int j = 1;
    int l = 0;
    while (i < n - 1) {
      // move right pointer to expand window
      while (j < n && nums[j] - nums[i] < 2) j++;
      // if subsequence satisfies the constraint, update max length
      if (nums[j - 1] - nums[i]) l = max(l, j - i);
      if (j == n) break;
      // move left pointer to shrink window
      while (i < j && nums[j] - nums[i] >= 2) i++;
    }
    return l;
  }
};
