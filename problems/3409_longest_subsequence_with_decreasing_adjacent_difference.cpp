class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    int n = nums.size();
    constexpr int MAXVAl = 300;
    vector<vector<int>> dp(MAXVAl + 1, vector<int>(MAXVAl + 1, 0));
    int out = 0;
    for (size_t i = 0; i < n; i++) {
      int x = nums[i];
      for (int j = 1; j <= 300; j++) {
        int d = abs(x - j);
        dp[x][d] = max(dp[x][d], dp[j][d] + 1);
      }
      dp[x][MAXVAl] = max(dp[x][300], 1);
      for (int j = MAXVAl - 1; j >= 0; j--)
        dp[x][j] = max(dp[x][j], dp[x][j + 1]);
      out = max(out, dp[x][0]);
    }
    return out;
  }
};
