class NumArray
{
private:
  vector<int> prefix;

public:
  NumArray(vector<int>& nums)
  {
    auto n = nums.size();
    prefix = vector<int>(n + 1);
    partial_sum(begin(nums), end(nums), next(begin(prefix)));
  }

  int sumRange(int left, int right)
  {
    return prefix[right + 1] - prefix[left];
  }
};
