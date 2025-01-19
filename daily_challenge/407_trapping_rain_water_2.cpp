class Solution {
	struct Cell{
		int h;
		int r;
		int c;

		bool operator < (const Cell& x) const {
			return h >= x.h;
		}
	};
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		const int m=heightMap.size(), n=heightMap[0].size();

		vector<vector<bool>> visit(m, vector<bool>(n));
		vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		priority_queue<Cell> q;

		//row
		for (int i=0; i<m; i++) {
			q.push(Cell {.h=heightMap[i][0], .r=i, .c=0});
			q.push(Cell {.h=heightMap[i][n-1], .r=i, .c=n-1});
			visit[i][0] = visit[i][n-1] = true;
		}
		//col
		for (int i=0; i<n; i++) {
			q.push(Cell {.h=heightMap[0][i], .r=0, .c=i});
			q.push(Cell {.h=heightMap[m-1][i], .r=m-1, .c=i});
			visit[0][i] = visit[m-1][i] = true;
		}
		int out=0;

		while (!q.empty()) {
			Cell cell = q.top(); q.pop();
			
			for (const auto&d: dir) {
				int r = cell.r+d[0], c=cell.c+d[1];
				if (r<0 || c<0 || r>=m || c>=n || visit[r][c]) continue;
				
				if(heightMap[r][c] < cell.h)
					out += cell.h - heightMap[r][c];

				q.push(Cell {.h=max(heightMap[r][c], cell.h), .r=r, .c=c});
				visit[r][c] = true;
			}
		}
		return out;
	}
};
