class Solution {
	public:
		vector<int> smallestRange(vector<vector<int>>& nums) {
			size_t tot = 0;
			size_t n = nums.size();
			for (const auto&num: nums) tot+=num.size();
			vector<pair<int, int>> v(tot);
			for (size_t i = 0, x = 0; i < n; ++i) {
				for (const auto&val : nums[i]) {
					v[x++] = {val, i};
				}
			}
			sort(v.begin(), v.end());
			size_t sw = 0;
			unordered_map<int, int> gp;
			long left = 0, right = LONG_MAX;
			for (size_t i = 0; i < tot; i++) {
				gp[v[i].second]++;
				while (gp.size() == n) {
					if (right-left > v[i].first-v[sw].first) {
						right = v[i].first;
						left = v[sw].first;
					}
					gp[v[sw].second]--;
					if (gp[v[sw].second] < 1) gp.erase(v[sw].second);
					sw++;
				}
			}
			return {(int)left, (int)right};
		}
};
