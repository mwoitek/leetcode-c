class Solution
{
public:
  int minSetSize(vector<int>& arr)
  {
    unordered_map<int, int> c;
    for (int i : arr) c[i]++;
    auto fs = vector<pair<int, int>>(c.begin(), c.end());
    sort(fs.begin(),
         fs.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
           return a.second > b.second;
         });
    auto n = arr.size();
    int r = 0;
    int j = 0;
    while (2 * r < n) r += fs[j++].second;
    return j;
  }
};
