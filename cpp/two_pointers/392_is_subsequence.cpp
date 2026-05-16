class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    auto ls = s.length();
    auto lt = t.length();
    if (ls > lt) return false;
    size_t i = 0;
    size_t j = 0;
    while (i < ls) {
      while (j < lt && s[i] != t[j]) j++;
      if (j == lt) return false;
      i++;
      j++;
    }
    return true;
  }
};
