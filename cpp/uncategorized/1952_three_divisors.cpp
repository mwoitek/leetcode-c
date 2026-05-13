class Solution
{
public:
  int isqrt(int n)
  {
    int lo = 0;
    int hi = n;
    int mid;
    long long sq;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      sq = 1LL * mid * mid;
      if (sq == n) return mid;
      if (sq > n) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return hi;
  }

  bool is_prime(int n)
  {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; d++) {
      if (n % d == 0) return false;
    }
    return true;
  }

  bool isThree(int n)
  {
    // To have exactly 3 divisors, an integer has to be equal to the square of a
    // prime.
    int s = isqrt(n);
    return 1LL * s * s == n && is_prime(s);
  }
};
