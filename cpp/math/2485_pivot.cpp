using ll = long long;

class Solution
{
public:
  int isqrt(int n)
  {
    if (n < 0) return -1;
    int lo = 0;
    int hi = n;
    int mid;
    ll sq;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      sq = static_cast<ll>(mid) * mid;
      if (sq == n) return mid;
      if (sq > n) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return -1;
  }

  int pivotInteger(int n)
  {
    // x^2 = (n*(n+1))/2
    // A solution exists only when the RHS is a perfect square.
    return isqrt((n * (n + 1)) / 2);
  }
};
