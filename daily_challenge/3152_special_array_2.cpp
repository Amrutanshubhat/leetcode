class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    const size_t n = nums.size();
    vector<int> dp(n, 1);

    for (size_t i = 1; i < n; i++) {
      // check for odd - even pair
      if ((nums[i] ^ nums[i - 1]) & 1)
        dp[i] += dp[i - 1];
    }

    vector<bool> ans;
    for (const auto &q : queries) {
      if ((dp[q[1]] - dp[q[0]]) != (q[1] - q[0]))
        ans.emplace_back(false);
      else
        ans.emplace_back(true);
    }
    return ans;
  }
};
