class Solution
{
public:
  int minStartValue(vector<int>& nums)
  {
    auto p = vector<int>(nums.size());
    partial_sum(nums.begin(), nums.end(), p.begin());
    auto it = min_element(p.begin(), p.end());
    int m = *it;
    return m < 1 ? 1 - m : 1;
  }
};
