class Solution {
  const int mod = 1e9 + 7;
  vector<int> dp;

public:
  int countGoodStrings(int low, int high, int zero, int one) {
    dp.resize(high + 1, -1);
    return dfs(low, high, zero, one, 0);
  }

private:
  int dfs(int l, int h, int z, int o, int cur) {
    if (cur > h)
      return 0;
    if (dp[cur] != -1)
      return dp[cur];
    size_t x = 0;
    if (cur >= l)
      x++;
    return dp[cur] = (x + ((size_t)dfs(l, h, z, o, cur + z) +
                           (size_t)dfs(l, h, z, o, cur + o)) %
                              mod) %
                     mod;
  }
};
