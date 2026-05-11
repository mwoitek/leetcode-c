class Solution
{
public:
  vector<int> findDisappearedNumbers(vector<int>& nums)
  {
    unordered_map<int, int> c;
    for (auto i : nums) c[i]++;
    vector<int> ans;
    auto n = nums.size();
    for (int i = 1; i <= n; i++) {
      if (!c.contains(i)) ans.push_back(i);
    }
    return ans;
  }
};
