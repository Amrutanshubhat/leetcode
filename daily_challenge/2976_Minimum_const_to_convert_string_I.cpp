class Solution {
	unordered_map<char, vector<pair<char, int>>> conn;

	void dijskstra(char src, vector<int>& d) {
		priority_queue<pair<int,char>> q;
		vector<bool> visit(26);
		q.push({0, src});
		d[src-'a'] = 0;
		while(!q.empty()) {
			char temp = q.top().second; q.pop();
			if (visit[temp-'a']) continue;
			visit[temp-'a'] = true;

			for (const auto&c: conn[temp]) {
				int pd = d[temp-'a']+c.second; 
				if (pd < d[c.first-'a']) {
					d[c.first-'a'] = pd;
					q.push({-pd, c.first});
				}
			}
		}

	}
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
		int n = original.size();
		for (int i=0; i<n; i++) {
			conn[original[i]].push_back({changed[i], cost[i]});
		}
    	long long tot_cost = 0;	
		vector<vector<int>> hash(26);
		for (int i=0; i<source.size(); i++) {
			if (source[i] != target[i]) {
				int si = source[i]-'a';
				int ti = target[i]-'a';
				if (hash[si].empty()) {
					//get shortest path
					hash[si].resize(26, INT_MAX);
					dijskstra(source[i], hash[si]);
				}
				//cout<<source[i]<<"->"<<target[i]<<"->"<<hash[si][ti]<<endl;
				if (hash[si][ti] == INT_MAX) return -1;
				tot_cost += hash[si][ti];
			}
		}
		return tot_cost;
    }
};
