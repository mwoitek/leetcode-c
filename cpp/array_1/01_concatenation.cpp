class Solution
{
public:
  vector<int> getConcatenation(vector<int>& nums)
  {
    auto n = nums.size();
    auto ans = vector<int>(2 * n);
    copy(begin(nums), end(nums), begin(ans));
    copy(begin(nums), end(nums), next(begin(ans), n));
    return ans;
  }
};
