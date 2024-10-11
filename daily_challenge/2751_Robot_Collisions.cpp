class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
		vector<pair<int, int>> r, l;
		int n = positions.size();
		for (int i=0; i<n; i++) {
			if (directions[i] == 'L') {
				l.push_back({positions[i], healths[i]});
			} else {
				r.push_back({positions[i], healths[i]});
			}
		}
		sort(r.begin(), r.end());
		sort(l.begin(), l.end());

		stack<pair<int,int>> s1, s2, s3;

		for (const auto&i: r) {
			s1.push(i);
		}
		for (const auto&i: l) {
			s2.push(i);
		}

		//output as per the input
		unordered_map<int, int> mp;
		while (!s1.empty()) {
			while (!s2.empty() && s1.top().first <= s2.top().first) {
				s3.push(s2.top());
				s2.pop();
			}
			//no left moving element to collide
			if (s3.empty()) {
				//no element left
				if (s2.empty()) break;
				mp[s1.top().first] = s1.top().second;
				s1.pop();
			} else {
				if (s3.top().second > s1.top().second) {
					s3.top().second -= 1;
					s1.pop();
				} else if (s3.top().second < s1.top().second) {
					s3.pop();
					s1.top().second -= 1;
				} else {
					s1.pop();
					s3.pop();
				}
			}
		}

		while (!s1.empty()) {
			mp[s1.top().first] = s1.top().second;
			s1.pop();
		}
		while (!s2.empty()) {
			mp[s2.top().first] = s2.top().second;
			s2.pop();
		}
		while (!s3.empty()) {
			mp[s3.top().first] = s3.top().second;
			s3.pop();
		}
		vector<int> out(mp.size());
		
		int i = 0;
		for (const auto& x: positions) {
			if (mp[x]) out[i++] = mp[x];
		}
		return out;
    }
};
