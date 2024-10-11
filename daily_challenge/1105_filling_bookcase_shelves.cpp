class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
		vector<int> dp(n+1, INT_MAX);
		dp[0] = 0;
		for (int i=0; i<n; i++) {
			int thick = 0;
			int maxh = 0;
			// onto new shelf
			for (int j=i; j>=0; j--) {
				thick += books[j][0];
				if (thick > shelfWidth) break;
				maxh = max(maxh, books[j][1]);
				dp[i+1] = min(dp[i+1], dp[j]+maxh);
			}
		}
		return dp[n];
    }
};
