class Solution {
  unordered_map<int, vector<pair<int, int>>> adj;
  vector<int> d;

public:
  int minimumObstacles(vector<vector<int>> &grid) {
    size_t m = grid.size(), n = grid[0].size();
	d.resize(m*n+1, INT_MAX);

    for (size_t i = 0; i < m-1; i++) {
      for (size_t j = 0; j < n-1; j++) {
        int a = i*n+1+j;
		adj[a].emplace_back(make_pair(a+1, grid[i][j+1]));
		adj[a+1].emplace_back(make_pair(a, grid[i][j]));
		adj[a].emplace_back(make_pair(a+n, grid[i+1][j]));
		adj[a+n].emplace_back(make_pair(a, grid[i][j]));
      }
	  //last col
	  int a = i*n+n;
	  adj[a].emplace_back(make_pair(a+n, grid[i+1][n-1]));
	  adj[a+n].emplace_back(make_pair(a, grid[i][n-1]));
    }
	//last row
	for (size_t i=0; i<n-1; i++) {
        int a = (m-1)*n+1+i;
		adj[a].emplace_back(make_pair(a+1, grid[m-1][i+1]));
		adj[a+1].emplace_back(make_pair(a, grid[m-1][i]));
	}
    shortest_path();
    return d[m * n];
  }

private:
  void shortest_path() {
    vector<bool> visit(d.size());
    priority_queue<pair<int, int>> q;
    q.emplace(make_pair(0, 1));
    d[1] = 0;

    while (!q.empty()) {
      int w = abs(q.top().first), node = q.top().second;
      q.pop();
      if (visit[node])
        continue;
      visit[node] = true;

      for (const auto &x : adj[node]) {
        if (d[x.first] > w + x.second) {
          d[x.first] = w + x.second;
          q.emplace(make_pair(-d[x.first], x.first));
        }
      }
    }
  }
};
