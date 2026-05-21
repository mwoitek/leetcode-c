class Solution
{
public:
  int arraySign(vector<int>& nums)
  {
    auto n = nums.size();
    auto cp =
        count_if(begin(nums), end(nums), [](int i) -> bool { return i > 0; });
    auto cn =
        count_if(begin(nums), end(nums), [](int i) -> bool { return i < 0; });
    if (cp + cn != n) return 0;
    return cn & 1 ? -1 : 1;
  }
};
