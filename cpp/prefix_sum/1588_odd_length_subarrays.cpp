class Solution
{
public:
  int sumOddLengthSubarrays(vector<int>& arr)
  {
    auto n = arr.size();
    auto pre = vector<int>(n + 1);
    partial_sum(arr.begin(), arr.end(), next(pre.begin()));
    int s = 0;
    for (size_t l = 0; l < n; l++) {
      for (size_t r = l; r < n; r += 2) {
        s += pre[r + 1] - pre[l];
      }
    }
    return s;
  }
};
