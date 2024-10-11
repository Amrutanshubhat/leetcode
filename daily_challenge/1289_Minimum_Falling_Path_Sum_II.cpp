class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

		for (int i=0; i<n; i++){
			dp[0][i] = grid[0][i];
		}

		for (int i=1; i<n; i++){
			for (int j=0; j<n; j++){
				for (int k=0; k<n; k++) {
					if (j==k) {
						continue;
					}
					dp[i][j] = min(dp[i][j], grid[i][j]+dp[i-1][k]);
				}
			}
		}
		int min_val = dp[n-1][0];
		for(int i=1; i<n; i++) {
			if (dp[n-1][i] < min_val) {
				min_val = dp[n-1][i];
			}
		}
		return min_val;
    }
};
