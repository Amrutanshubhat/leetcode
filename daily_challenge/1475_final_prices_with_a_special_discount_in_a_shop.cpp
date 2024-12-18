class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    vector<int> out(prices.size());
    for (int i = 0; i < prices.size(); i++) {
      int j = i + 1;
      while (j < prices.size() && prices[j] > prices[i])
        j++;
      if (j == prices.size()) {
        out[i] = prices[i];
      } else {
        out[i] = prices[i] - prices[j];
      }
    }
    return out;
  }
};
