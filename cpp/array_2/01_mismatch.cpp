class Solution
{
public:
  vector<int> findErrorNums(vector<int>& nums)
  {
    unordered_map<int, int> c;
    for (auto i : nums) c[i]++;
    auto ans = vector<int>(2);
    auto n = nums.size();
    for (int i = 1; i <= n; i++) {
      if (c[i] == 1) continue;
      if (!c[i]) {
        ans[1] = i;
      } else {
        ans[0] = i;
      }
    }
    return ans;
  }
};
