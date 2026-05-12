class Solution
{
public:
  bool canMakeArithmeticProgression(vector<int>& arr)
  {
    sort(begin(arr), end(arr));
    auto n = arr.size();
    int d = arr[1] - arr[0];
    for (size_t i = 1; i < n - 1; i++) {
      if (d != arr[i + 1] - arr[i]) return false;
    }
    return true;
  }
};
