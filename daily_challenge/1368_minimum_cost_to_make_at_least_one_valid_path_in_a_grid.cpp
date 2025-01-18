class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
		int m=grid.size(); int n=grid[0].size();

		vector<vector<int>> d(m, vector<int>(n, INT_MAX));
		vector<vector<bool>> visit(m, vector<bool>(n));
		vector<vector<int>> dir = {
			{0, 1}, {0, -1}, {1, 0}, {-1, 0}
		};
		priority_queue<pair<int, pair<int, int>>> q;

		q.push({0, {0, 0}});
		d[0][0] = 0;

		while (!q.empty()) {
			int r = q.top().second.first;
			int c = q.top().second.second;
			q.pop();
			if (visit[r][c]) continue;
			visit[r][c] = true;

			for (int i=0; i<4; i++) {
				int cost = grid[r][c] == i+1 ? 0 : 1;
				int nr = r+dir[i][0];
				int nc = c+dir[i][1];
				if (nc >= n || nc < 0 || nr < 0 || nr >= m)
					continue;
				if (d[r][c]+cost < d[nr][nc]) {
					d[nr][nc] = d[r][c]+cost;
					q.push({-d[nr][nc], {nr, nc}});
				}
			}
		}
		return d[m-1][n-1];
    }
};
