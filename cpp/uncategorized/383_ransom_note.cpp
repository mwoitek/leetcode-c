class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    unordered_map<char, int> c;
    for (auto l : magazine) c[l]++;
    for (auto l : ransomNote) {
      if (!c[l]) return false;
      c[l]--;
    }
    return true;
  }
};
