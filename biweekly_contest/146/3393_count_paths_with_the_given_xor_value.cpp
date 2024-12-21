class Solution {
  int row, col;
  vector<vector<vector<int>>> dp;
#define MOD (((long)1e9) + 7)
public:
  int countPathsWithXorValue(vector<vector<int>> &grid, int k) {
    this->row = grid.size();
    this->col = grid[0].size();
    dp.resize(row, vector<vector<int>>(col, vector<int>(16, -1)));
    return dfs(0, 0, grid, k, 0);
  }

private:
  int dfs(int r, int c, vector<vector<int>> &grid, int k, int tot) {
    if (r >= row || c >= col)
      return 0;
    if (dp[r][c][tot] > -1)
      return dp[r][c][tot];
    if (r == row - 1 && c == col - 1 && ((tot ^ grid[r][c]) == k)) {
      return 1;
    }
    dp[r][c][tot] = dfs(r, c + 1, grid, k, tot ^ grid[r][c]) % MOD;
    return dp[r][c][tot] = ((dfs(r + 1, c, grid, k, tot ^ grid[r][c]) % MOD) +
                            dp[r][c][tot]) %
                           MOD;
  }
};
