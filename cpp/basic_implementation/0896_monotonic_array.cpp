class Solution
{
public:
  bool isMonotonic(vector<int>& nums)
  {
    auto n = nums.size();
    size_t i = 1;
    while (i < n && nums[i] == nums[0]) i++;
    if (i == n) return true;
    bool incr = nums[i] > nums[0];
    for (size_t j = i; j < n - 1; j++) {
      if (nums[j] == nums[j + 1]) continue;
      if ((nums[j + 1] > nums[j] && !incr) || (nums[j + 1] < nums[j] && incr))
        return false;
    }
    return true;
  }
};
