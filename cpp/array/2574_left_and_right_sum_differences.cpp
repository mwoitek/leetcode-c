class Solution
{
public:
  vector<int> leftRightDifference(vector<int>& nums)
  {
    auto n = nums.size();

    auto leftSum = vector<int>(n);
    partial_sum(nums.begin(), prev(nums.end()), next(leftSum.begin()));

    auto rightSum = vector<int>(n);
    partial_sum(nums.rbegin(), prev(nums.rend()), next(rightSum.rbegin()));

    auto answer = vector<int>(n);
    for (size_t i = 0; i < n; i++) {
      answer[i] = abs(leftSum[i] - rightSum[i]);
    }
    return answer;
  }
};
