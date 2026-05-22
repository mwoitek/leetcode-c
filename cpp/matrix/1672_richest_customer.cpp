class Solution
{
public:
  int maximumWealth(vector<vector<int>>& accounts)
  {
    auto m = accounts.size();
    auto w = vector<int>(m);
    for (size_t c = 0; c < m; c++) {
      auto r = accounts[c];
      w[c] = accumulate(r.begin(), r.end(), int());
    }
    auto it = max_element(w.begin(), w.end());
    auto i = distance(w.begin(), it);
    return w[i];
  }
};
