class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    auto n = s.length();
    if (n != t.length()) return false;
    unordered_map<char, int> cs, ct;
    for (size_t i = 0; i < n; i++) {
      cs[s[i]]++;
      ct[t[i]]++;
    }
    if (cs.size() != ct.size()) return false;
    for (auto& [l, c] : cs) {
      if (ct[l] != c) return false;
    }
    return true;
  }
};
