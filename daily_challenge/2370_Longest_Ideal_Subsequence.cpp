class Solution {
public:
    int longestIdealString(string s, int k) {
		int n = s.size();
		int dp[26] = {0};

		for (const auto&c:s) {
			int val = c - 'a';
			int max_ = 0;
			for (int i=max(0, val-k); i<=min(25, val+k); i++){
				if (dp[i] > max_) {
					max_ = dp[i];
				}
			}
			dp[val] = max_+1;
		}
		
		int out = dp[0];
		for (int i=0; i<26; i++){
			if (dp[i] > out)
				out = dp[i];
		}
		return out;
    }
};
