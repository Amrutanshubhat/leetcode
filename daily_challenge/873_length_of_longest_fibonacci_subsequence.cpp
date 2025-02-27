class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
		const int n = arr.size();
		int dp[n][n];
		memset(dp, 0, sizeof(dp));

		unordered_map<long, int> ht;
		int out = 0;
		for (int i=0; i<n; i++) {
			ht[arr[i]] = i;
			for (int j=i-1; j>0; j--) {
				int val = arr[i]-arr[j];

				auto it = ht.find(val);
				if (it != ht.end() && (val < arr[j] && it->second < j)) {
					dp[j][i] = dp[it->second][j]+1;
				}
				
				if (out < dp[j][i])
					out = dp[j][i];
			}
		}
		return out == 0 ? out : out+2;
    }
};
