class Solution {
	unordered_map<int, vector<int>> adj;
	vector<int> visit;
	vector<bool> v;
	int max_val;
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
		visit.resize(amount.size(), -1);
		v.resize(amount.size());
		max_val = INT_MIN;
       	for (const auto& edge: edges) {
			adj[edge[0]].push_back(edge[1]);
			adj[edge[1]].push_back(edge[0]);
		}

		dfs(bob, 0);
		dfs2(0, 0, 0, amount);
		return max_val;
    }
private:
	bool dfs(int node, int cnt) {
		if (visit[node] != -1) return false;

		visit[node] = cnt;
		if (node == 0) return true;

		for (const auto&i: adj[node]) {
			if (dfs(i, cnt+1)) return true;
		}
		visit[node] = -1; //can't reach root
		return false;
	}

	void dfs2(int node, int cost, int cnt, vector<int>& amount) {

		int c = cost;

		if (visit[node] == cnt) 
			c += amount[node]/2;

		else if (visit[node] == -1 || visit[node] > cnt)
			c += amount[node];

		v[node] = true;

		bool leaf = true;
		for (const auto&i: adj[node]) {
			if (!v[i]) {
				leaf = false;
				dfs2(i, c, cnt+1, amount);
			}
		}
		if (leaf) {
			max_val = max(max_val, c);
		}
	}
};
