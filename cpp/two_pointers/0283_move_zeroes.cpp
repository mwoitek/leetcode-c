class Solution
{
public:
  void moveZeroes(vector<int>& nums)
  {
    auto n = nums.size();
    size_t i = 0;
    for (size_t j = 0; j < n; j++) {
      if (!nums[j]) continue;
      nums[i++] = nums[j];
    }
    for (size_t j = i; j < n; j++) nums[j] = 0;
  }
};
