class Solution
{
public:
  int maxArea(vector<int>& height)
  {
    auto n = height.size();
    int l = 0;
    int r = n - 1;
    int a = 0;
    while (l < r) {
      int b = r - l;
      int h = height[l] < height[r] ? height[l++] : height[r--];
      a = max(a, b * h);
    }
    return a;
  }
};
