class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
		const size_t n = favorite.size();
		vector<int> deg(n);

		for (int i=0; i<n; i++)
			deg[favorite[i]]++;

		queue<int> start;
		for (int i=0; i<n; i++)
			if (deg[i] == 0) start.push(i);

		vector<int> depth(n, 1);
		while (!start.empty()) {
			int cur = start.front(); start.pop();
			int next = favorite[cur];
			depth[next] = max(depth[next], depth[cur]+1);
			if (--deg[next] == 0)
				start.push(next);
		}

		int fav_pair = 0;
		int max_cycle = 0;
		for (int i=0; i<n; i++) {
			if (deg[i] == 0) continue;
			int cycle = 0;
			for (int j=i; deg[j] != 0; j=favorite[j]) {
				deg[j] = 0;
				cycle++;
			}
			if (cycle == 2)
				fav_pair += depth[i]+depth[favorite[i]];
			else
				max_cycle = max(max_cycle, cycle);
		}
		return max(fav_pair, max_cycle);
    }
};
