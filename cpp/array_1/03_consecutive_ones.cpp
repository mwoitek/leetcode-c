class Solution
{
public:
  int findMaxConsecutiveOnes(vector<int>& nums)
  {
    int m = 0;
    auto b = begin(nums);
    auto it = find(b, end(nums), 1);
    auto j = distance(b, it);
    auto n = nums.size();
    while (j < n) {
      int c = 1;
      for (size_t k = j; k < n - 1 && nums[k] & nums[k + 1]; k++) c++;
      if (c > m) m = c;
      b = next(b, c);
      it = find(b, end(nums), 1);
      j = distance(begin(nums), it);
    }
    return m;
  }
};
