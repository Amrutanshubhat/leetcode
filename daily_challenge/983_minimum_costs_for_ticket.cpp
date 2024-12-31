class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    size_t n = days.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (size_t i = 1; i <= n; i++) {
      dp[i] = min(dp[i], dp[i - 1] + costs[0]);
      for (size_t j = i; j <= n && days[j - 1] < days[i - 1] + 7; j++) {
        dp[j] = min(dp[j], dp[i - 1] + costs[1]);
      }
      for (size_t j = i; j <= n && days[j - 1] < days[i - 1] + 30; j++) {
        dp[j] = min(dp[j], dp[i - 1] + costs[2]);
      }
    }
    return dp[n];
  }
};
