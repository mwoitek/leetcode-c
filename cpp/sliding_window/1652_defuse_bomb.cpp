class Solution
{
public:
  int get_index(int i, int n)
  {
    while (i < 0) i += n;
    return i % n;
  }

  vector<int> decrypt(vector<int>& code, int k)
  {
    auto n = code.size();
    auto ans = vector<int>(n);
    if (!k) return ans;
    int s = k > 0 ? 1 : -1;
    int t = 0;
    for (int i = 1; i <= s * k; i++) {
      t += code[get_index(s * i, n)];
    }
    int l = s;
    int r = k;
    if (s < 0) swap(l, r);
    for (int i = 0; i < n; i++) {
      ans[i] = t;
      t = t - code[get_index(l, n)] + code[get_index(r + 1, n)];
      l++;
      r++;
    }
    return ans;
  }
};
