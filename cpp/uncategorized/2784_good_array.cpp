class Solution
{
public:
  bool isGood(vector<int>& nums)
  {
    unordered_map<int, int> c;
    for (int i : nums) c[i]++;
    auto n = nums.size() - 1;
    if (c[n] != 2) return false;
    for (int i = 1; i < n; i++) {
      if (c[i] != 1) return false;
    }
    return true;
  }
};
