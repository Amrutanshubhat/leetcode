class Solution {
	vector<vector<int>> adj, mem;
	vector<bool> visit;
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		adj.resize(numCourses);
		mem.resize(numCourses, vector<int>(numCourses, -1));
		visit.resize(numCourses);
	   for (const auto&pr: prerequisites)
		   adj[pr[1]].push_back(pr[0]);

	   vector<bool> out;
	   for (const auto&q: queries)
		   out.push_back(dfs(q[0], q[1]));

	   return out;
    }
private:
	// a prereq of b
	bool dfs(int a, int b) {
		if (a == b) return true;
		if (visit[b]) return false;
		if (mem[a][b] != -1) return mem[a][b];
		visit[b] = true;
		bool found=false;
		for (const auto&node: adj[b]) {
			found = dfs(a, node);
			if (found) break;
		}
		visit[b] = false;
		return mem[a][b] = found;
	}
};
