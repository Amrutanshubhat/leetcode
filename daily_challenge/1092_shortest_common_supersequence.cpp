class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
		const int m = str1.size(), n = str2.size();
		int dp[m+1][n+1]; memset(dp, 0, sizeof(dp));

		// when other string is empty
		for (int i=0; i<=m; i++)
			dp[i][0] = i;

		for (int i=0; i<=n; i++)
			dp[0][i] = i;

		// longest common subsequence
		for (int i=1; i<=m; i++) {
			for (int j=1; j<=n; j++) {
				if (str1[i-1] == str2[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else
					dp[i][j] = 1+min(dp[i][j-1], dp[i-1][j]); // not max
			}
		}

		// construct sequence
		string out;
		int i=m, j=n;
		while (i && j) {
			if (str1[i-1] == str2[j-1]) {
				out += str1[i-1];
				i--; j--;
			} else if (dp[i-1][j] < dp[i][j-1]) {
				out += str1[i-1];
				i--;
			} else {
				out += str2[j-1];
				j--;
			}
		}
		while (i) out += str1[--i];
		while (j) out += str2[--j];

		reverse(out.begin(), out.end());
		return out;
    }
};
