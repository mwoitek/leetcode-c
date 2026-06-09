class Solution
{
public:
  vector<int> findDuplicates(vector<int>& nums)
  {
    vector<int> ans;
    sort(nums.begin(), nums.end());
    size_t i = 1;
    while (i < nums.size()) {
      if (nums[i] == nums[i - 1]) ans.push_back(nums[i++]);
      i++;
    }
    return ans;
  }
};
