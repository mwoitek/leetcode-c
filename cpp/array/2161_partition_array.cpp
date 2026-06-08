class Solution
{
public:
  vector<int> pivotArray(vector<int>& nums, int pivot)
  {
    vector<int> ans;
    ans.reserve(nums.size());
    vector<int> gt;
    int eq = 0;
    for (int n : nums) {
      if (n < pivot)
        ans.push_back(n);
      else if (n > pivot)
        gt.push_back(n);
      else
        eq++;
    }
    while (eq > 0) {
      ans.push_back(pivot);
      eq--;
    }
    ans.insert(ans.end(), gt.begin(), gt.end());
    return ans;
  }
};
