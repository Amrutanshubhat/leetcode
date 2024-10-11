class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
		int n = nums.size();
		int dp[n+1];
		memset(dp, 0, sizeof(dp));
		for (int i=0; i<n; i++) {
			dp[i+1] = (dp[i]%p+nums[i]%p)%p;
		}
		if (!dp[n]) return 0;
		int out = n;
		unordered_map<int, int> m{{0, 0}};
		for (int i=1; i<=n; i++) {
			int r = (dp[i]+p-dp[n])%p;
			auto it = m.find(r);
			if (it != m.end()) {
				out = min(out, i - it->second);
			}
			m[dp[i]] = i;
		}
		return out == n ? -1 : out;
    }
};
