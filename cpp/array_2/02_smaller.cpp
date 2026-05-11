class Solution
{
public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums)
  {
    auto n = nums.size();
    auto ans = vector<int>(n);
    int c;
    for (size_t i = 0; i < n; i++) {
      c = 0;
      for (size_t j = 0; j < n; j++) {
        if (i == j) continue;
        if (nums[j] < nums[i]) c++;
      }
      ans[i] = c;
    }
    return ans;
  }
};
