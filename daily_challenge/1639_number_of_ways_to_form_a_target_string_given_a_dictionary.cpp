class Solution {
  vector<vector<int>> f, dp;
  const int mod = 1e9 + 7;
  size_t n;

public:
  int numWays(vector<string> &words, string target) {
    n = words.front().size();
    f.resize(n, vector<int>(26));
    dp.resize(n, vector<int>(target.size(), -1));

    for (const auto &word : words) {
      for (size_t i = 0; i < n; i++) {
        f[i][word[i] - 'a']++;
      }
    }
    return fill(target, 0, 0);
  }

private:
  int fill(string &target, int w, int t) {
    if (t == target.size())
      return 1;
    if (w == n)
      return 0;
    if (dp[w][t] != -1)
      return dp[w][t];

    int idx = target[t] - 'a';
    dp[w][t] = fill(target, w + 1, t);
    if (f[w][idx] > 0) {
      size_t tot = f[w][idx] * (size_t)fill(target, w + 1, t + 1);
      dp[w][t] = (dp[w][t] + (tot % mod)) % mod;
    }
    return dp[w][t];
  }
};
