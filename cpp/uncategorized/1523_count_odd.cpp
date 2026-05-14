class Solution
{
public:
  int countOdds(int low, int high)
  {
    int n = high - low + 1;
    int c = n / 2;
    if (low & 1 && high & 1) c++;
    return c;
  }
};
