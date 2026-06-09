class Solution
{
public:
  long long maxTotalValue(vector<int>& nums, int k)
  {
    auto [mi, ma] = minmax_element(nums.begin(), nums.end());
    return 1LL * k * (*ma - *mi);
  }
};
