class Solution {
	struct {
		bool operator() (const vector<int>& x, const vector<int>& y) {
			return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
		}
	}cust_sort;
public:
    int minGroups(vector<vector<int>>& intervals) {
       	sort(intervals.begin(), intervals.end(), cust_sort);
		priority_queue<int, vector<int>, greater<int>> q;

		for (const auto&interval: intervals) {
			if (!q.empty() && q.top() < interval[0]) {
				q.pop();
			}
			q.push(interval[1]);
		}

		return q.size();
    }
};
