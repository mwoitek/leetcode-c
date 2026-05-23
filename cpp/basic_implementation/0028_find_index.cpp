// This problem can be solved very easily by using the find method for strings.
// But I believe the idea of this problem is to implement this functionality
// from scratch. This is why I have the following "longer" solution.

class Solution
{
public:
  bool check_substring(string& haystack, int i, string& needle)
  {
    for (size_t j = 1; j < needle.length(); j++) {
      if (haystack[i + j] != needle[j]) return false;
    }
    return true;
  }

  int strStr(string haystack, string needle)
  {
    auto lh = haystack.length();
    auto ln = needle.length();
    if (ln > lh) return -1;
    for (int i = 0; i < lh - ln + 1; i++) {
      if (haystack[i] != needle[0]) continue;
      if (check_substring(haystack, i, needle)) return i;
    }
    return -1;
  }
};
