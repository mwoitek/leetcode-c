class Solution
{
public:
  int arrayPairSum(vector<int>& nums)
  {
    sort(nums.rbegin(), nums.rend());
    int s = 0;
    for (size_t i = 1; i < nums.size(); i += 2) {
      s += nums[i];
    }
    return s;
  }
};
