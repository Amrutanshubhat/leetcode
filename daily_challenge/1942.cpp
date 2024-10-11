class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
		size_t n = times.size();
		vector<pair<int, int>> v(n);        
		for (size_t i=0; i<n; i++) {
			v[i] = make_pair(times[i][0], i);
		}
		sort(v.begin(), v.end());
		vector<int> chair(n);
		for (const auto&p: v) {
			size_t t=0;
			//move until lesser numbered chair available
			while (chair[t] != 0 && chair[t] > p.first) t++;
			// desired friend
			if (targetFriend == p.second) {
				return t;
			}
			// mark the duration for the chair
			chair[t] = times[p.second][1];

		}
		return n;
    }
};
