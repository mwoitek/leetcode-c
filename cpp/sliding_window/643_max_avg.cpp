class Solution
{
public:
  double findMaxAverage(vector<int>& nums, int k)
  {
    auto n = nums.size();
    auto s = accumulate(begin(nums), next(begin(nums), k), int());
    auto m = s;
    for (int i = 1; i < n - k + 1; i++) {
      s = s - nums[i - 1] + nums[i + k - 1];
      m = max(m, s);
    }
    return m / (1.0 * k);
  }
};
