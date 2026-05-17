class Solution
{
public:
  char findTheDifference(string s, string t)
  {
    sort(begin(s), end(s));
    sort(begin(t), end(t));
    auto l = s.length();
    for (size_t i = 0; i < l; i++) {
      if (s[i] != t[i]) return t[i];
    }
    return t[l];
  }
};
