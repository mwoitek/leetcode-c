class Solution
{
public:
  int compress(vector<char>& chars)
  {
    auto n = chars.size();
    int i = 0;
    int j = 1;
    int k = 0;
    while (i < n && j <= n) {
      while (j < n && chars[j] == chars[i]) j++;
      chars[k++] = chars[i];
      int g = j - i;
      if (g > 1) {
        for (char d : to_string(g)) chars[k++] = d;
      }
      i = j++;
    }
    return k;
  }
};
