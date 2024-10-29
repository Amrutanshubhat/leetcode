class Solution {
  vector<vector<int>> dp;

public:
  int maxMoves(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int out = 0;
    dp.resize(m, vector<int>(n, -1));
    for (size_t i = 0; i < m; i++) {
      out = max(out, dfs(grid, i, 0));
    }
    return out;
  }

private:
  int dfs(vector<vector<int>> &grid, int r, int c) {
    if (c == grid[0].size() - 1)
      return 0;

    if (dp[r][c] != -1)
      return dp[r][c];

    int _a = 0, _b = 0, _c = 0;

    if (grid[r][c + 1] > grid[r][c])
      _a = 1 + dfs(grid, r, c + 1);

    if (r != 0 and grid[r - 1][c + 1] > grid[r][c])
      _b = 1 + dfs(grid, r - 1, c + 1);

    if (r != grid.size() - 1 and grid[r + 1][c + 1] > grid[r][c])
      _c = 1 + dfs(grid, r + 1, c + 1);

    dp[r][c] = max({_a, _b, _c});
    return dp[r][c];
  }
};
