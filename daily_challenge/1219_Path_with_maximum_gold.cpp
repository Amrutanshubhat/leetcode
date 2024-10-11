class Solution {
	int dfs(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& v) {
		if (i>=m || j>=n || i<0 || j<0 || v[i][j] || grid[i][j] == 0) {
			return 0;
		}
		v[i][j] = true;
		int max_reach = max ({
				dfs(grid, i, j+1, m, n, v),
				dfs(grid, i, j-1, m, n, v),
				dfs(grid, i+1, j, m, n, v),
				dfs(grid, i-1, j, m, n, v),
				});
		v[i][j] = false;
		return grid[i][j]+max_reach;
	}
public:
    int getMaximumGold(vector<vector<int>>& grid) {
		int max_cnt = 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> v(m, vector<int>(n));
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				max_cnt = max(max_cnt, dfs(grid, i, j, m, n, v));
			}
		}
		return max_cnt;
    }
};
