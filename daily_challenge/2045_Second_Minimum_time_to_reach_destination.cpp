class Solution {
	unordered_map<int, vector<int>> conn;

	int next_time(int cur_time, int time, int change) {
		//check color
		bool red = (cur_time/change) & 1;
		int wait_time = 0;
		if (red) {
			wait_time = change - cur_time%change;
		}
		return wait_time+time+cur_time;
	}

public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
		for (const auto&e: edges) {
			conn[e[0]].push_back(e[1]);
			conn[e[1]].push_back(e[0]);
		}
		vector<pair<int,int>> mind(n+1, {INT_MAX, INT_MAX});
		queue<pair<int,int>> q;
		q.push({1, 0});
		while (!q.empty()) {
			const auto [node, cst] = q.front();q.pop();
			for (const auto&e: conn[node]) {
				int nxt = next_time(cst, time, change);
				if (mind[e].first > nxt) {
					mind[e].first = nxt;
					q.push({e, nxt});
				} else if (mind[e].first < nxt && nxt < mind[e].second) {
					if (e == n) return nxt;
					mind[e].second = nxt;
					q.push({e, nxt});
				}
			}
		}
		return -1;
    }
};
