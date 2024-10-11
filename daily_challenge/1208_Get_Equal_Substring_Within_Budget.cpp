class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
		int n = s.size();
    	vector<pair<int,int>> dp(n);
		int maxlen = 0;
		dp[0] = {0,maxCost-abs(s[0]-t[0])};

		if (dp[0].second >= 0)
			maxlen = 1;

		for (int i=1; i<n; i++) {
			dp[i] = {dp[i-1].first, dp[i-1].second-abs(s[i]-t[i])};
			while (dp[i].first<i && dp[i].second<0) {
				dp[i].second = dp[i].second+abs(s[dp[i].first]-t[dp[i].first]);
				dp[i].first = dp[i].first+1;
			}
			if (dp[i].second >= 0) {
				maxlen = max(maxlen, 1 + i - dp[i].first);
			}
		}

		return maxlen;
    }
};
