class Solution
{
public:
  bool valid_map(string& s, string& t)
  {
    unordered_map<char, char> m;
    auto l = s.length();
    for (size_t i = 0; i < l; i++) {
      char cs = s[i];
      char ct = t[i];
      if (m.contains(cs) && m[cs] != ct) return false;
      m[cs] = ct;
    }
    return true;
  }

  bool isIsomorphic(string s, string t)
  {
    return valid_map(s, t) && valid_map(t, s);
  }
};
