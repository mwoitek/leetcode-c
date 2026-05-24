class Solution
{
public:
  int removeDuplicates(vector<int>& nums)
  {
    auto n = nums.size();
    int i = 0;
    int j = 1;
    int k = 0;
    while (i < n && j <= n) {
      while (j < n && nums[j] == nums[i]) j++;
      nums[k++] = nums[i];
      if (j - i > 1) nums[k++] = nums[i];
      i = j++;
    }
    return k;
  }
};
