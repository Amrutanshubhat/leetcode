class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		const int m=isWater.size(), n=isWater[0].size();
		vector<vector<int>> out(m, vector<int>(n, -1));
		vector<pair<int, int>> dir = {
			{-1, 0}, {1, 0}, {0, 1}, {0, -1}
		};
		queue<pair<int, int>> q;
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (isWater[i][j]) {
					q.emplace(make_pair(i, j));
				}
			}
		}
		int w=0;
		while (!q.empty()) {
			int br = q.size();
			while (br--) {
				int i=q.front().first, j=q.front().second; q.pop();
				if (out[i][j] != -1) continue;
				out[i][j] = w;
				for (const auto& d: dir)  {
					int nr = i+d.first, nc=j+d.second;
					if (nr >= 0 && nr < m && nc >= 0 && nc < n)
						q.emplace(make_pair(nr, nc));
				}
			}
			w++;
		}
		return out;
    }
};
