class Solution
{
public:
  string convertToTitle(int columnNumber)
  {
    stringstream ss;
    while (columnNumber > 0) {
      auto d = columnNumber % 26;
      if (!d) d = 26;
      auto ch = static_cast<char>(d + 'A' - 1);
      ss << ch;
      columnNumber = (columnNumber - d) / 26;
    }
    auto ans = ss.str();
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
