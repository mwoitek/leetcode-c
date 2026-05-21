class Solution
{
public:
  bool lemonadeChange(vector<int>& bills)
  {
    array<int, 2> m = {0, 0};
    for (int b : bills) {
      if (b == 5) {
        m[0]++;
      } else if (b == 10) {
        if (!m[0]) return false;
        m[0]--;
        m[1]++;
      } else {
        if (m[0] && m[1]) {
          m[0]--;
          m[1]--;
        } else if (m[0] >= 3) {
          m[0] -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
