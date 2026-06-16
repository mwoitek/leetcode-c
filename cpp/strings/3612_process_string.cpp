class Solution
{
public:
  string processStr(string s)
  {
    string ans;
    for (auto c : s) {
      switch (c) {
        case '*':
          if (ans.length() > 0) ans.pop_back();
          break;
        case '#':
          ans.append(ans.begin(), ans.end());
          break;
        case '%':
          reverse(ans.begin(), ans.end());
          break;
        default:
          ans.push_back(c);
      }
    }
    return ans;
  }
};
