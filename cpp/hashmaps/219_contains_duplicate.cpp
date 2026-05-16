class Solution
{
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k)
  {
    unordered_map<int, int> idx;
    auto s = nums.size();
    int n;
    for (int i = 0; i < s; i++) {
      n = nums[i];
      if (idx.contains(n) && i - idx[n] <= k) return true;
      idx[n] = i;
    }
    return false;
  }
};
