class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
		int max_val=0;
		unordered_map<int, int> ht;
		for (const auto&c: nums) {
			if (c > max_val) max_val = c;
			ht[c] = 1;
		}
		const int max_sqrt = sqrt(max_val);
		for (const auto&c: nums) {
			int x=c, cnt=1;
			for (;x<=max_sqrt && ht[x] > 0; x*=x) {
				ht[x] = max(ht[x], cnt++);
			}
			if (ht[x] > 0)
				ht[x] = max(ht[x], cnt);
		}
		int out = -1;
		for (const auto&c: nums) {
			if (ht[c] > 1)
				out = max(out, ht[c]);
		}
		return out;
    }
};
