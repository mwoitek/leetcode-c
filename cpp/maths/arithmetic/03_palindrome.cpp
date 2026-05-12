class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0) return false;
    if (x < 10) return true;
    vector<int> d;
    while (x) {
      d.push_back(x % 10);
      x /= 10;
    }
    auto n = d.size();
    size_t j = n & 1 ? n / 2 : n / 2 - 1;
    for (size_t i = 0; i <= j; i++) {
      if (d[i] != d[n - i - 1]) return false;
    }
    return true;
  }
};
