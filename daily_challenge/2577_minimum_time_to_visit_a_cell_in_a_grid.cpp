class Solution {
	vector<vector<pair<int, int>>> adj;
	vector<int> dist;
public:
    int minimumTime(vector<vector<int>>& grid) {
		if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
		size_t m=grid.size(), n=grid[0].size();
		adj.resize(m*n+1);
		dist.resize(m*n+1, INT_MAX);
		dist[1] = 0;	

		//fill adj matrix
		for (size_t i=0; i<m-1; i++) {
			for (size_t j=0; j<n-1; j++) {
				size_t node = i*n+1+j;
				//next col
				adj[node].emplace_back(make_pair(node+1, grid[i][j+1]));
				adj[node+1].emplace_back(make_pair(node, grid[i][j]));

				//next row
				adj[node].emplace_back(make_pair(node+n, grid[i+1][j]));
				adj[node+n].emplace_back(make_pair(node, grid[i][j]));
			}
			//last col
			size_t node = (i+1)*n;
			adj[node].emplace_back(make_pair(node+n, grid[i+1][n-1]));
			adj[node+n].emplace_back(make_pair(node, grid[i][n-1]));
		}
		//last row
		for (size_t j=0; j<n-1; j++) {
			size_t node = (m-1)*n+1+j;
			adj[node].emplace_back(make_pair(node+1, grid[m-1][j+1]));
			adj[node+1].emplace_back(make_pair(node, grid[m-1][j]));
		}
		shortest_path();
		return dist[m*n];
    }
private:
	void shortest_path() {
		vector<bool> visit(dist.size());
		priority_queue<pair<int, int>> q;
		q.emplace(make_pair(0, 1));

		while (!q.empty()) {
			int w = abs(q.top().first), cur=q.top().second; q.pop();
			if (visit[cur]) continue;
			visit[cur] = true;
			for (const auto&node: adj[cur]) {
				int x=node.first, min_dist=node.second;
				int cost = w+1;
				if (cost < min_dist) {
					cost = (((min_dist-cost+1)/2)*2)+cost;
				}
				if (cost < dist[x]) {
					dist[x] = cost;
					q.emplace(make_pair(-dist[x], x));
				}
			}
		}
	}
};
