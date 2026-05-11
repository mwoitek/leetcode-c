class Solution
{
public:
  vector<string> buildArray(vector<int>& target, int n)
  {
    vector<string> ans;
    int i = 0;
    auto l = target.size();
    for (int j = 1; j <= n; j++) {
      ans.push_back("Push");
      if (j == target[i]) {
        i++;
        if (i == l) break;
      } else {
        ans.push_back("Pop");
      }
    }
    return ans;
  }
};
