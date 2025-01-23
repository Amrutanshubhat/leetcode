class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
       	const int m=grid.size(), n=grid[0].size();
		vector<vector<bool>> visit(m, vector<bool>(n));

		int out=0;
		for (int i=0; i<m; i++) {
			int cnt=0;
			for (int j=0; j<n; j++) {
				if (grid[i][j])
					cnt++;
			}
			if (cnt < 2) continue;
			for (int j=0; j<n; j++) {
				if (grid[i][j])
					visit[i][j] = true;
			}
			out += cnt;
		}
		for (int j=0; j<n; j++) {
			int cnt=0, v=0;
			for (int i=0; i<m; i++) {
				if (grid[i][j]) {
					if (visit[i][j]) v++;
					cnt++;
				}
			}
			if (cnt > 1)
				out += cnt-v;
		}
		return out;

    }
};
