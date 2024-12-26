class Solution {
  int offset;
  vector<vector<int>> dp;

public:
  int findTargetSumWays(vector<int> &nums, int target) {
    this->offset = accumulate(nums.begin(), nums.end(), 0);
    dp.resize(nums.size(), vector<int>(2 * offset + 1, -1));
    return dfs(nums, 0, 0, target);
  }

private:
  int dfs(vector<int> &nums, int idx, int tot, int target) {
    if (idx == nums.size()) {
      if (tot == target)
        return 1;
      return 0;
    }
    if (dp[idx][tot + offset] == -1) {
      dp[idx][tot + offset] = dfs(nums, idx + 1, tot + nums[idx], target) +
                              dfs(nums, idx + 1, tot - nums[idx], target);
    }
    return dp[idx][tot + offset];
  }
};
