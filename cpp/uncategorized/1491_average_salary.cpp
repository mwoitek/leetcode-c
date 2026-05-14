class Solution
{
public:
  double average(vector<int>& salary)
  {
    sort(begin(salary), end(salary));
    auto s = accumulate(next(begin(salary)), prev(end(salary)), int());
    auto n = salary.size() - 2;
    return s / (1.0 * n);
  }
};
