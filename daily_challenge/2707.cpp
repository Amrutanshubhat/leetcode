class Solution {
	unordered_map<string, bool> m;
public:
    int minExtraChar(string s, vector<string>& dictionary) {
		for (const auto&key: dictionary) {
			m[key] = true;
		}
       	int n = s.size();
		vector<int> dp(n+1, INT_MAX);
		dp[0] = 0;
		for (int i=1; i<=n; i++) {
			dp[i] = dp[i-1]+1;
			for (int j=i; j > 0; j--) {
				if (m.find(s.substr(j-1, i-j+1)) != m.end()) {
					dp[i] = min(dp[j-1], dp[i]);
				}
			}
		}
		return dp[n];
    }
};
