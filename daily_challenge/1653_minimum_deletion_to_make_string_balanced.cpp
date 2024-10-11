class Solution {
public:
    int minimumDeletions(string s) {
		int n = s.size();
		vector<pair<int,int>> dp(n+1);

		for (int i=1; i<=n; i++) {
			dp[i] = dp[i-1];
			if (s[i-1] == 'a') {
				dp[i].first++;
			} else {
				dp[i].second++;
			}
			//printf("%d: %d %d\n", i, dp[i].first, dp[i].second);
		}
		int out = INT_MAX;
		for (int i=1; i<=n; i++) {
			int ac = dp[n].first - dp[i].first;
			int bc = dp[i-1].second;
			if (ac + bc < out) {
				out = ac+bc;
			}
		}
		return out == INT_MAX ? 0 : out;

    }
};
