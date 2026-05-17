class Solution
{
public:
  int jump(vector<int>& nums)
  {
    auto n = nums.size();
    auto jumps = vector<int>(n);
    size_t i = 0;
    size_t j = 0;
    while (i < n && j < n - 1) {
      size_t k = min(i + nums[i], n - 1);
      int v = jumps[i++] + 1;
      for (size_t m = k; m > j; m--) jumps[m] = v;
      j = max(j, k);
    }
    return jumps.back();
  }
};
