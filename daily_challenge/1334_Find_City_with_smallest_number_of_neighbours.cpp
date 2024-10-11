class Solution {
	unordered_map<int, vector<pair<int, int>>> conn;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		for (const auto&e: edges) {
			conn[e[0]]. push_back({e[1], e[2]});
			conn[e[1]]. push_back({e[0], e[2]});
		}
		int out = INT_MIN;
		int cnt = INT_MAX;
		//SPFA for each node
		for (int x=0; x<n; x++) {
			int cur_cnt = 0;
			vector<int> dist(n, INT_MAX);
			dist[x] = 0;
			queue<int> q;
			q.push(x);

			while (!q.empty()) {
				int temp = q.front(); q.pop();
				for (const auto&e: conn[temp]) {
					int d = dist[temp] + e.second;
					if (dist[e.first] > d) {
						q.push(e.first);
						dist[e.first] = d;
					}
				}
			}

			for (const auto&d: dist) {
				if (d <= distanceThreshold && d > 0) {
					cur_cnt++;
				}
			}
			if (cur_cnt > 0 && cnt >= cur_cnt) {
				cnt = cur_cnt;
				out = max(out, x);
			}
		}
		return out;
    }
};
