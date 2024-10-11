class Solution {
	unordered_map<int, vector<int>> adj;

	void connect_edges(vector<vector<int>>& edges){
		for(const auto&e:edges){
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
	}

	vector<vector<int>> bfs(int root, int n){
		queue<int> q;
		vector<bool> v(n); 
		q.push(root);
		q.push(-1);
		vector<vector<int>> path;
		vector<int> p;
		while(!q.empty()){
			int temp = q.front(); q.pop();
			if (temp == -1) {
				if (!q.empty()) {
					q.push(-1);
				}
				if (!p.empty()){
					path.push_back(p);
					p.clear();
				}
			}
			else{
				v[temp] = true;
				p.push_back(temp);
				for (const auto& node: adj[temp]) {
					if (v[node]) continue;
					q.push(node);
				}
			}
		}
		return path;
	}

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    	connect_edges(edges);
		vector<int> out;
		vector<vector<int>> p1, p2;
		p1 = bfs(0, n);
		p2 = bfs(p1[p1.size()-1][0], n);

		int h = p2.size()-1;
		int mid = h/2;
		//2 roots
		if (h%2) {
			out.push_back(p2[mid][0]);
			out.push_back(p2[mid+1][0]);
		}
		else{
			out.push_back(p2[mid][0]);
		}

		return out;
    }
};
