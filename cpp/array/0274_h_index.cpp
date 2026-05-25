class Solution
{
public:
  int hIndex(vector<int>& citations)
  {
    sort(citations.rbegin(), citations.rend());
    auto n = citations.size();
    int i = 1;
    while (i <= n && citations[i - 1] >= i) i++;
    return --i;
  }
};
