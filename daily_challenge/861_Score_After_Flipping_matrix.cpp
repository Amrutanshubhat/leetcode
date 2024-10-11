class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
 		int m = grid.size();
		int n = grid[0].size();

		for (int i=0; i<m; i++) {
			if (grid[i][0] == 0) {
				for (auto& j:grid[i]) {
					j = !j;
				}
			}
		}

		for (int i=0; i<n; i++) {
			int cnt = 0;
			for (int j=0; j<m; j++) {
				if (grid[j][i])
					cnt++;
			}
			if (cnt < m-cnt) {
				for (int j=0; j<m; j++) {
					grid[j][i] = !grid[j][i];
				}
			}
		}
		int tot = 0;
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				tot += grid[i][j]*pow(2, n-1-j);
			}
		}
		return tot;
    }
};
