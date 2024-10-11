class Solution {
	struct mysort {
		bool operator() (vector<int> a, vector<int> b) {
			return a[0] > b[0];
		}
	}mysort;
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		sort(edges.begin(), edges.end(), mysort);
		int cnt = 0;	
		Union_Find alice(n), bob(n);


		for (const auto&e : edges) {
			switch (e[0]) {
				case 3:
					if (!alice.same_set(e[1], e[2])) {
						alice.unite(e[1], e[2]);
						bob.unite(e[1], e[2]);
						cnt++;
				}
				break;

				case 2:
					//only bob
					if (!bob.same_set(e[1], e[2])) {
						bob.unite(e[1], e[2]);
						cnt++;
				}
				break;
				case 1:
					//only alice
					if (!alice.same_set(e[1], e[2])) {
						alice.unite(e[1], e[2]);
						cnt++;
				}
				break;
			}
		}

		if (alice.reacheable() && bob.reacheable()) {
			return edges.size() - cnt;
		}

		return -1;
	}
};
