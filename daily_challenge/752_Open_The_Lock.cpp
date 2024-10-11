class Solution {
	unordered_map<int, vector<int>> adj;
	int LIMIT = 10000;
	string make_str(int x){
		string s = to_string(x);
		s.insert(0, 4 - s.size(), '0');
		return s;
	}

	void construct_graph(){
		for(int i=0; i<LIMIT; i++){
			string s = make_str(i);
			for(int j=0; j<4; j++){
				string t = s;
				t.replace(j, 1, 1, char('0'+(((s[j]-'0')+11) % 10)));
				adj[i].push_back(stoi(t));
				t = s;
				t.replace(j, 1, 1, char('0'+(((s[j]-'0')+9) % 10)));
				adj[i].push_back(stoi(t));
			}
		}
	}

	int shortest_path(unordered_map<int, bool>& deadend, string& target){
		vector<bool> visit(LIMIT);
		vector<int> d(LIMIT, INT_MAX);
		priority_queue<pair<int, int>> q;
		int tar = stoi(target);
		if (!tar) return -1;
		q.push({0, 0});
		d[0] = 0;
		while(!q.empty()){
			pair<int, int> temp = q.top();
			q.pop();
			if (visit[temp.second]) continue;
			visit[temp.second] = true;
			for(auto &i:adj[temp.second]){
				if (!deadend[i] && d[i] > d[temp.second]+1){
					d[i] = d[temp.second]+1;
					q.push({-d[i], i});
				}
			}
		}
		if (d[tar] == INT_MAX) return -1;
		return d[tar];

	}

public:
    int openLock(vector<string>& deadends, string target) {
		construct_graph();
		unordered_map<int, bool> de;
		for(auto&i:deadends){
			de[stoi(i)] = true;
		}
        return shortest_path(de, target);
    }
};
