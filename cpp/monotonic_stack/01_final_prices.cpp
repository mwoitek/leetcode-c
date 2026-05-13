class Solution
{
public:
  vector<int> finalPrices(vector<int>& prices)
  {
    auto answer = vector<int>(prices);
    auto b = next(begin(prices));
    auto n = prices.size();
    for (size_t i = 0; i < n; i++) {
      auto it = find_if(b, end(prices), [&prices, i](int p) -> bool {
        return p <= prices[i];
      });
      if (it != end(prices)) answer[i] -= *it;
      b = next(b);
    }
    return answer;
  }
};
