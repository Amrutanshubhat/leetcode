class Solution {
	unordered_map<int, vector<int>> adj;
	vector<vector<int>> out;
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
		unordered_map<int, int> id, od;
		for (const auto& pair: pairs) {
			adj[pair[0]].push_back(pair[1]);
			id[pair[1]]++; od[pair[0]]++;
		}
		int start = pairs.front()[0];
		for (const auto& pair: pairs) {
			if (od[pair[0]] > id[pair[0]]) {
				start = pair[0];
				break;
			}
		}
		dfs(start);
		// reverse the order to print from start
		reverse(out.begin(), out.end());
		return out;
    }
private:
	void dfs(int node) {
		while (!adj[node].empty()) {
			int x = adj[node].back();
			adj[node].pop_back();
			dfs(x);
			out.push_back({node, x});
		}
	}
};
