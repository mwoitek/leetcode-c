class Solution
{
public:
  int titleToNumber(string columnTitle)
  {
    int ans = 0;
    int p = 1;
    auto n = columnTitle.length();
    for (int i = n - 1; i >= 0; i--) {
      int d = columnTitle[i] - 'A' + 1;
      ans += d * p;
      if (i > 0) p *= 26;
    }
    return ans;
  }
};
