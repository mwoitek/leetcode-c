int maxProfit(int* prices, int pricesSize)
{
  int i, j, profit = 0;

  for (i = 0; i < pricesSize - 1; i++) {
    for (j = i + 1; j < pricesSize; j++) {
      if (prices[j] - prices[i] > profit) {
        profit = prices[j] - prices[i];
      }
    }
  }
  return profit;
}
