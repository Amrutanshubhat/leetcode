class Solution {
	void fill_adj(vector<vector<int>>& adj, vector<vector<int>>& inp) {
		// conn[1] -> conn[0]
		for (const auto&conn: inp) {
			adj[conn[1]].push_back(conn[0]);
		}
	}
	
	void dfs(vector<vector<int>>& adj, unordered_map<int, int>& v, vector<bool>& perm, vector<bool>& temp, int node, int& c) {
		if (perm[node] || temp[node]) return;
		temp[node] = true;
		for (const auto& x: adj[node]) {
			dfs(adj, v, perm, temp, x, c);
			if (!perm[x]) return;
		}
		v[node] = c++;
		perm[node] = true;
	}

	// topological sort using dsf
	bool top_sort(vector<vector<int>>& adj, unordered_map<int, int>& v, int k) {
		vector<bool> perm(k+1);
		int c = 1;
		for (int i=1; i<=k; i++) {
			vector<bool> temp(k+1);
			dfs(adj, v, perm, temp,  i, c);
			if (!perm[i]) return false;
		}
		return true;

	}
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
		vector<vector<int>> adj_col(k+1), adj_row(k+1);	
		unordered_map<int, int> sc, sr;

		fill_adj(adj_col, colConditions);
		fill_adj(adj_row, rowConditions);

		if (!top_sort(adj_col, sc, k) || !top_sort(adj_row, sr, k)) {
			// cycle encountered
			return {};
		}
		vector<vector<int>> out(k, vector<int>(k));

		// for each value check which row and col it belongs to
		int last_r = k, last_c = k;
		for (int i=1; i<=k; i++) {
			int c = sc[i]==0 ? last_c-- : sc[i];
			int r = sr[i]==0 ? last_r-- : sr[i];

			out[r-1][c-1] = i;
		}
		return out;
    }
};
