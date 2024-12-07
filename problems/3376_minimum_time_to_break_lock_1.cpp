class Solution {
public:
  int findMinimumTime(vector<int> &strength, int K) {
    size_t n = strength.size();
    size_t perm = 1 << n;
    vector<int> dp(perm, INT_MAX);
    dp[0] = 0;

    for (size_t i = 0; i < perm; i++) {
      if (dp[i] == INT_MAX)
        continue; // invalid state

      int processed = __builtin_popcount(i);
      // updated value of x
      int x = 1 + processed * K;

      for (size_t j = 0; j < n; j++) {
        // if not processed yet
        if (!(i & (1 << j))) {
          int next = i | (1 << j);
          int time = ((strength[j] + x - 1) / x) + dp[i]; // next state+cur
                                                          // state
          dp[next] = dp[next] < time ? dp[next] : time;
        }
      }
    }
    return dp[perm - 1];
  }
};
