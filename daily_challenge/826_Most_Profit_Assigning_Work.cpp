class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
 		priority_queue<pair<int,int>, vector<pair<int,int>>> q;       
		int n = profit.size();

		for (int i=0; i<n; i++) {
			q.push({profit[i], difficulty[i]});
		}
		sort (worker.begin(), worker.end(), [](int a, int b) {return a > b;});

		int tot = 0;
		for (const auto&w: worker) {
			while (!q.empty() && q.top().second > w) q.pop();
			if (q.empty()) break;
			tot += q.top().first;
		}

		return tot;
    }
};
