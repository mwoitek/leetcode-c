class Solution
{
public:
  bool check(vector<int>& nums)
  {
    auto n = nums.size();
    int i = 1;
    while (i < n && nums[i] >= nums[i - 1]) i++;
    if (i == n) return true;
    for (int j = i + 1; j < i + n; j++) {
      if (nums[j % n] < nums[(j - 1) % n]) return false;
    }
    return true;
  }
};
