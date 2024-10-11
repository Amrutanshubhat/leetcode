class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		vector<pair<int,int>> v;
		int n = profits.size();

		for (int i=0; i<n; i++) {
			v.push_back({capital[i], profits[i]});
		}
		sort(v.begin(), v.end());

		auto it = v.begin();
		priority_queue<int,vector<int>> q;

		for (int i=0; i<k; i++) {
			while (it != v.end() && it->first <= w) {
				q.push(it->second);
				it++;
			}
			if (q.empty()) break;
			w += q.top();
			q.pop();

		}
		return w;
    }
};
