class Solution
{
public:
  set<int> get_divisors(int n)
  {
    set<int> d{1, n};
    for (int i = 2; i * i <= n; i++) {
      if (n % i) continue;
      d.insert(i);
      d.insert(n / i);
    }
    return d;
  }

  int commonFactors(int a, int b)
  {
    auto da = get_divisors(a);
    auto db = get_divisors(b);
    vector<int> c;
    set_intersection(da.begin(),
                     da.end(),
                     db.begin(),
                     db.end(),
                     back_inserter(c));
    return c.size();
  }
};
