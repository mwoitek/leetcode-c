class Solution
{
public:
  string mergeAlternately(string word1, string word2)
  {
    auto l1 = word1.length();
    auto l2 = word2.length();
    auto merged = string(l1 + l2, 'x');
    size_t i = 0;
    auto n = min(l1, l2);
    for (size_t j = 0; j < n; j++) {
      merged[i++] = word1[j];
      merged[i++] = word2[j];
    }
    if (n == l1) {
      for (size_t j = n; j < l2; j++) merged[i++] = word2[j];
    } else {
      for (size_t j = n; j < l1; j++) merged[i++] = word1[j];
    }
    return merged;
  }
};
