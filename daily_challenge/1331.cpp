class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
		int n = arr.size();
		if (!n) return {};
       	vector<pair<int, int>> rank;
		for (int i=0; i<n; i++) {
			rank.emplace_back(make_pair(arr[i], i));
		}
		sort(rank.begin(), rank.end());
		vector<int> out(n);
		int r = 1;
		out[rank[0].second] = r;
		for (int i=1; i<n; i++) {
			if (rank[i].first == rank[i-1].first) {
				out[rank[i].second] = r;
			} else {
				out[rank[i].second] = ++r;
			}
		}
		return out;
    }
};
