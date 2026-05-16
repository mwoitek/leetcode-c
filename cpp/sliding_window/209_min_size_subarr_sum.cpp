class Solution
{
public:
  int minSubArrayLen(int target, vector<int>& nums)
  {
    auto n = nums.size();
    int l = n + 1;
    int i = 0;
    int j = 1;
    long long t = nums[0];
    while (i < n) {
      while (j < n && t < target) t += nums[j++];
      if (t < target) break;
      l = min(l, j - i);
      while (i < n && t >= target) t -= nums[i++];
      l = min(l, j - i + 1);
    }
    return l <= n ? l : 0;
  }
};
