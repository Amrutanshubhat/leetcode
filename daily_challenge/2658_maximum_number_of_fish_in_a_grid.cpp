class Solution {
	vector<vector<bool>> visit;
	vector<pair<int, int>> dir;
	int m, n;
public:
    int findMaxFish(vector<vector<int>>& grid) {
       	m=grid.size(), n=grid[0].size();
		visit.resize(m, vector<bool>(n));
		dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
		int out=0;
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				out = max(out, dfs(grid, i, j));
		return out;
    }
private:
	int dfs(vector<vector<int>>& grid, int i, int j) {
		if (i<0 || j<0 || i>=m || j>=n || visit[i][j] || grid[i][j]==0) return 0;
		visit[i][j] = true;
		int dist=grid[i][j];
		for (const auto&d: dir)
			dist += dfs(grid, i+d.first, j+d.second);
		return dist;
	}
};
