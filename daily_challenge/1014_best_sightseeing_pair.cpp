class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    size_t n = values.size();
    vector<int> dp(n);
    dp[0] = values[0];
    for (int i = 1; i < values.size(); i++) {
      dp[i] = max(dp[i - 1] - values[i - 1] + values[i],
                  values[i - 1] + values[i]) -
              1;
    }
    return *max_element(dp.begin(), dp.end());
  }
};
