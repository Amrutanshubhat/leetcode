class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
       	const size_t n=grid[0].size(); 
		grid[1][n-1] = 0;

		vector<vector<size_t>> ps(2, vector<size_t>(n+2));
		for (int i=1; i<=n; i++) {
			ps[0][i] = ps[0][i-1]+grid[0][i-1];
			ps[1][n-i+1] = ps[1][n-i+2]+grid[1][n-i];
		}

		size_t out = SIZE_MAX;
		for (size_t i=1; i<=n; i++) {
			size_t tot = max(ps[0][n]-ps[0][i], ps[1][1]-ps[1][i]);
			if (tot < out)
				out = tot;
		}
		return out;
    }
};
