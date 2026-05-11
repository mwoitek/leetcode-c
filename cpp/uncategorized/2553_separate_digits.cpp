class Solution
{
public:
  vector<int> separateDigits(vector<int>& nums)
  {
    vector<int> d;
    int i;
    for (auto it = rbegin(nums); it != rend(nums); it = next(it)) {
      i = *it;
      if (i < 10) {
        d.push_back(i);
        continue;
      }
      while (i) {
        d.push_back(i % 10);
        i /= 10;
      }
    }
    auto answer = vector<int>(rbegin(d), rend(d));
    return answer;
  }
};
