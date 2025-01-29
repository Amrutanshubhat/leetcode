class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    	const int n = edges.size();
		UnionFind uf(n);
		vector<int> out(2);
		for (const auto& edge: edges) {
			if (!uf.insert(edge[0], edge[1])) {
				out[0] = edge[0];
				out[1] = edge[1];
			}
		}
		return out;
    }
private:
	struct UnionFind {
		vector<int> root;
		vector<int> members;

		UnionFind(int n) {
			root.resize(n+1); members.resize(n+1, 1);
			for (int i=1; i<=n; i++) root[i] = i;
		}
		
		int findRoot(int a) {
			int r=root[a];
			while (r != root[r])
				r = root[r];
			return r;
		}

		bool insert(int a, int b) {
			int r1 = findRoot(a);
			int r2 = findRoot(b);

			// forms cycle
			if (r1 == r2) return false;

			if (members[r1] < members[r2])
				swap(r1, r2);

			members[r1] += members[r2];
			root[r2] = r1;

			return true;
		}
	};
};
