class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
		vector<vector<char>> grid(m, vector<char>(n, 'f'));
		
		for (const auto& pos: walls) {
			grid[pos[0]][pos[1]] = 'w';
		}

		for (const auto& pos: guards) {
			int x = pos[0], y=pos[1];
			grid[x][y] = 'g';

			//north
			for (int i=x-1; i>=0; i--) {
				if (grid[i][y] == 'g' || 
					grid[i][y] == 'w' || 
					grid[i][y] == 'u' ) {
					break;
				}
				grid[i][y] = 'u';

			}
			//south
			for (int i=x+1; i < m; i++) {
				if (grid[i][y] == 'g' || 
					grid[i][y] == 'w' || 
					grid[i][y] == 'u' ) {
					break;
				}
				grid[i][y] = 'u';

			}
			//east
			for (int i=y+1; i<n; i++) {
				if (grid[x][i] == 'g' || 
					grid[x][i] == 'w' || 
					grid[x][i] == 'r' ) {
					break;
				}
				grid[x][i] = 'r';

			}
			//west
			for (int i=y-1; i>=0; i--) {
				if (grid[x][i] == 'g' || 
					grid[x][i] == 'w' || 
					grid[x][i] == 'r' ) {
					break;
				}
				grid[x][i] = 'r';

			}
		}

		int cnt = 0;
		for (const auto&x: grid) {
			for (const auto&y: x) {
				if (y == 'f') cnt++;
			}
		}
		return cnt;
    }
};
